///////////////////////////////////////////////////////////////////////////
//
// File: laserdevice.hh
// Author: Andrew Howard
// Date: 28 Nov 2000
// Desc: Simulates the Player CLaserDevice (the SICK laser)
//
// CVS info:
//  $Source: /home/tcollett/stagecvs/playerstage-cvs/code/stage/include/laserdevice.hh,v $
//  $Author: rtv $
//  $Revision: 1.22 $

//
// Usage:
//  (empty)
//
// Theory of operation:
//  (empty)
//
// Known bugs:
//  (empty)
//
// Possible enhancements:
//  (empty)
//
///////////////////////////////////////////////////////////////////////////

#ifndef LASERDEVICE_HH
#define LASERDEVICE_HH

#include "playerdevice.hh"
#include "laserbeacon.hh"

#include <slist.h> // STL

typedef std::slist< int > LaserBeaconList; 

class CLaserDevice : public CEntity
{
  // Default constructor
  public: CLaserDevice(CWorld *world, CEntity *parent );

  // Load the entity from the worldfile
  public: virtual bool Load(CWorldFile *worldfile, int section);
  
  // Update the device
  public: virtual void Update( double sim_time );

  // Check to see if the configuration has changed
  private: bool CheckConfig();

  // Generate scan data
  private: bool GenerateScanData(player_laser_data_t *data);

  // Laser scan rate in samples/sec
  private: double scan_rate;

  // Minimum resolution in degrees
  private: double min_res;
  
  // Maximum range of sample in meters
  private: double max_range;

  // Laser configuration parameters
  private: double scan_res;
  private: double scan_min;
  private: double scan_max;
  private: int scan_count;
  private: bool intensity;

  // List of beacons detected in last scan
  public: LaserBeaconList m_visible_beacons;

#ifdef INCLUDE_RTK2

  // Initialise the rtk gui
  protected: virtual void RtkStartup();

  // Finalise the rtk gui
  protected: virtual void RtkShutdown();

  // Update the rtk gui
  protected: virtual void RtkUpdate();
  
  // For drawing the laser scan
  private: rtk_fig_t *scan_fig;

#endif
  
};

#endif















