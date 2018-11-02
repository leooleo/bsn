#include "bsn/data/RawData.h"

namespace bsn {
    namespace data {
        
        using namespace std;
        
        RawData::RawData() : m_sensor_data(), m_time() {}
        
        RawData::RawData(const double &sensor_data,const std::string &sensor_type ,const std::string &ts): 
            m_sensor_data(sensor_data),
            m_sensor_type(sensor_type),
            m_time(ts) {}
        
        RawData::~RawData() {}
        
        RawData::RawData(const RawData &obj) :
            SerializableData(),
            m_sensor_data(obj.getSensorData()),
            m_sensor_type(obj.getSensorType()),
            m_time(obj.getTime()) {}
        
        RawData& RawData::operator=(const RawData &obj) {
            m_sensor_data = obj.getSensorData();
            m_sensor_type = obj.getSensorType();
            m_time = obj.getTime();          
            return (*this);
        }
        
        int32_t RawData::ID() {
            return 880;
        }
        const string RawData::ShortName() {
            return "RawData";
        }
        const string RawData::LongName() {
            return "data.RawData";
        }
        
        int32_t RawData::getID() const {
            return RawData::ID();
        }

        const string RawData::getShortName() const {
            return RawData::ShortName();
        }

        const string RawData::getLongName() const {
            return RawData::LongName();
        }

        void RawData::setSensorData(const double &sensor_data) {
            m_sensor_data = sensor_data;
        }
        
        double RawData::getSensorData() const {
            return m_sensor_data;
        }

        void RawData::setTime(const std::string &ts) {
            m_time = ts;
        }

        std::string RawData::getTime() const {
            return m_time;
        }

        void RawData::setSensorType(const string &type) {
            m_sensor_type = type;
        }

        string RawData::getSensorType() const {
            return m_sensor_type;
        }
        
        ostream& RawData::operator<<(ostream &out) const {
            odcore::serialization::SerializationFactory& sf=odcore::serialization::SerializationFactory::getInstance();
            std::shared_ptr<odcore::serialization::Serializer> s = sf.getQueryableNetstringsSerializer(out);
            
            s->write(1, m_sensor_data);
            s->write(2, m_sensor_type);
            s->write(3, m_time);

            return out;
        }
        
        istream& RawData::operator>>(istream &in) {
            odcore::serialization::SerializationFactory& sf=odcore::serialization::SerializationFactory::getInstance();
            std::shared_ptr<odcore::serialization::Deserializer> d = sf.getQueryableNetstringsDeserializer(in);
            
            d->read(1, m_sensor_data);
            d->read(2, m_sensor_type);
            d->read(3, m_time);

            return in;
        }
        
        const string RawData::toString() const {
            stringstream sstr;

            sstr << "Raw Data: " << m_sensor_data << "" << endl;

            return sstr.str();
        }
    }
}