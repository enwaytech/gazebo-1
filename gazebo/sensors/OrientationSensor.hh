/*
 * Copyright (C) 2015 Open Source Robotics Foundation
 *
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 *     http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 *
*/

#ifndef __GAZEBO_ORIENTATION_SENSOR_HH_
#define __GAZEBO_ORIENTATION_SENSOR_HH_

#include <string>

#include <sdf/sdf.hh>

#include "gazebo/sensors/Sensor.hh"
#include "gazebo/common/CommonTypes.hh"
#include "gazebo/physics/PhysicsTypes.hh"
#include "gazebo/sensors/SensorTypes.hh"
#include "gazebo/transport/TransportTypes.hh"
#include "gazebo/util/system.hh"

namespace gazebo
{
  namespace sensors
  {
    /// \addtogroup gazebo_sensors
    /// \{

    /// \class OrientationSensor OrientationSensor.hh sensors/sensors.hh
    /// \brief OrientationSensor to provide orientation measurement
    class GAZEBO_VISIBLE OrientationSensor: public Sensor
    {
      /// \brief Constructor.
      public: OrientationSensor();

      /// \brief Destructor.
      public: virtual ~OrientationSensor();

      // Documentation inherited
      public: virtual void Load(const std::string & _worldName,
                                sdf::ElementPtr _sdf);

      // Documentation inherited
      public: virtual void Load(const std::string & _worldName);

      // Documentation inherited
      public: virtual void Init();

      // Documentation inherited
      protected: virtual bool UpdateImpl(bool _force);

      // Documentation inherited
      public: virtual void Fini();

      /// \brief Accessor for current orientation as an Euler angle
      /// \return Current Euler orientation
      public: math::Vector3 GetEulerOrientation() const;

      /// \brief Accessor for current orientation as a quaternion
      /// \return Current quaternion orientation
      public: math::Quaternion GetQuaternionOrientation() const

      /// \brief Mutex to protect reads and writes.
      private: mutable boost::mutex mutex;
      
      /// \brief Sensor data publisher.
      private: transport::PublisherPtr orientPub;

      /// \brief Topic name for data publisher.
      private: std::string topicName;

      /// \brief Parent link of this sensor.
      private: physics::LinkPtr parentLink;

      /// \brief Stores most recent orientation
      private: msgs::Magnetometer orientMsg;
    };
    /// \}
  }
}
#endif