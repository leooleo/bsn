#ifndef FILTERED_DATA_H_
#define FILTERED_DATA_H_

#include "opendavinci/odcore/data/SerializableData.h"
#include "opendavinci/odcore/serialization/Deserializer.h"
#include "opendavinci/odcore/serialization/SerializationFactory.h"
#include "opendavinci/odcore/serialization/Serializer.h"

namespace bsn {
    namespace data {
        
        using namespace std;
        using namespace odcore::data;
        
        class FilteredData : public SerializableData {
        
            public:
                //construtor parametrizado
                FilteredData(const double &/*filtered data*/);

                FilteredData();            // construtor
                virtual ~FilteredData();   // destrutor

                //Boas práticas do manual do OpenDaVINCI
                FilteredData(const FilteredData & /*obj*/);
                FilteredData& operator=(const FilteredData &/*obj*/);
            
            // Métodos abstratos
            public:
                virtual int32_t getID() const;
                virtual const string getShortName() const;
                virtual const string getLongName() const;

                static int32_t ID();
                static const string ShortName();
                static const string LongName();
        
            public:
                virtual ostream& operator<<(ostream &out) const;
                virtual istream& operator>>(istream &in);
        
                virtual const string toString() const;
                
            // setters e getters
            public:
                void setSensorData(const double &/*sensor_data*/);
                double getSensorData() const;
            
            private:
                double m_sensor_data; // estado do sensor 
        };
    }
}

#endif