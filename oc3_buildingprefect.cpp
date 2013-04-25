#include "oc3_buildingprefect.hpp"
#include "oc3_picture.hpp"
#include "oc3_resourcegroup.hpp"
#include "oc3_positioni.hpp"
#include "oc3_walker.hpp"

BuildingPrefect::BuildingPrefect() : ServiceBuilding(S_PREFECT)
{
  setType(B_PREFECT);
  _size = 1;
  setPicture( Picture::load( ResourceGroup::security, 1 ) );

  _animation.load( ResourceGroup::security, 2, 10);
  _animation.setFrameDelay( 4 );
  _animation.setOffset( Point( 20, 36 ) );
  _fgPictures.resize(1);
}

int BuildingPrefect::getServiceDelay() const
{
  float koeff = ( getWorkers() > 0 ) ? (float)getMaxWorkers() / (float)getWorkers() : 1.f;
  return (int)(ServiceBuilding::getServiceDelay() * koeff);
}

void BuildingPrefect::timeStep(const unsigned long time)
{
  bool mayAnimate = getWorkers() > 0;

  if( mayAnimate && _animation.isStopped() )
  {
    _animation.start();
  }

  if( !mayAnimate && _animation.isRunning() )
  {
    _animation.stop();
  }

  ServiceBuilding::timeStep( time );
}

void BuildingPrefect::deliverService()
{
  if( getWorkers() > 0 )
  {
    ServiceWalker *walker = new ServiceWalker(getService());
    walker->setServiceBuilding(*this);
    walker->start();

    _addWalker( walker );
  }
}

BuildingPrefect* BuildingPrefect::clone() const
{
  return new BuildingPrefect(*this);
}