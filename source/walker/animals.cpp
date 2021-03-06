// This file is part of openCaesar3.
//
// openCaesar3 is free software: you can redistribute it and/or modify
// it under the terms of the GNU General Public License as published by
// the Free Software Foundation, either version 3 of the License, or
// (at your option) any later version.
//
// openCaesar3 is distributed in the hope that it will be useful,
// but WITHOUT ANY WARRANTY; without even the implied warranty of
// MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
// GNU General Public License for more details.
//
// You should have received a copy of the GNU General Public License
// along with openCaesar3.  If not, see <http://www.gnu.org/licenses/>.

#include "animals.hpp"
#include "core/variant.hpp"
#include "game/city.hpp"
#include "game/pathway_helper.hpp"
#include "core/gettext.hpp"
#include "game/tilemap.hpp"

class Animal::Impl
{
public:
  TilePos destination;
};

Animal::Animal( CityPtr city )
  : Walker( city ), _d( new Impl )
{
  _setType( WT_NONE );
  _setGraphic( WG_NONE );

  setName( _("##Animal##") );
}

void Animal::send2City(const TilePos &start )
{
  if( !isDeleted() )
  {
    _getCity()->addWalker( WalkerPtr( this ) );
  }
}

Animal::~Animal()
{

}

void Animal::save( VariantMap& stream ) const
{
  Walker::save( stream );
  stream[ "destination" ] = _d->destination;
}

void Animal::load( const VariantMap& stream )
{
  Walker::load( stream );
  _d->destination = stream.get( "destination" ).toTilePos();
}

void Animal::_findNewWay( const TilePos& start )
{
  int loopIndex = 0;
  bool foundPath = false;
  do
  {
    const Tilemap& tmap = _getCity()->getTilemap();
    int range = 10;
    TilePos dest( std::rand() % range- range / 2, std::rand() % range - range / 2 );
    dest = (start+dest).fit( TilePos( 0, 0 ), TilePos( tmap.getSize()-1, tmap.getSize()-1 ) );

    if( tmap.at( dest ).isWalkable( true) )
    {
      PathWay pathway = PathwayHelper::create( _getCity(), start, dest, PathwayHelper::allTerrain );

      if( pathway.isValid() )
      {
        foundPath = true;
        setPathWay( pathway );
        setIJ( start );
        go();
      }
    }
  }
  while( !foundPath && ++loopIndex < 20 );

  if( !foundPath )
  {
    deleteLater();
  }
}



Sheep::Sheep( CityPtr city ) : Animal( city )
{
  _setGraphic( WG_ANIMAL_SHEEP_WALK );
  _setType( WT_ANIMAL_SHEEP );
  setName( _("##Sheep##") );
}

WalkerPtr Sheep::create(CityPtr city)
{
  WalkerPtr ret( new Sheep( city ) );
  ret->drop();

  return ret;
}

void Sheep::onDestination()
{
  Walker::onDestination();

  _findNewWay( getIJ() );
}

void Sheep::onNewTile()
{
  Walker::onNewTile();
  _getAnimation().setFrameDelay( 3 );
}

void Sheep::send2City(const TilePos &start )
{
  _findNewWay( start );

  if( !isDeleted() )
  {
    _getCity()->addWalker( this );
  }
}
