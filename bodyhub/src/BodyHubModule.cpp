#include "BodyHubModule.h"

#include "opendavinci/odcore/base/FIFOQueue.h"

#include "openbasn/data/SensorData.h"

#include <iostream>

using namespace std;

using namespace odcore::base;
using namespace odcore::base::module;
using namespace odcore::data;

using namespace openbasn::data;

BodyHubModule::BodyHubModule(const int32_t &argc, char **argv) :
    TimeTriggeredConferenceClientModule(argc, argv, "bodyhub")
     {}

BodyHubModule::~BodyHubModule() {}

void BodyHubModule::setUp() {}

void BodyHubModule::tearDown() {}

odcore::data::dmcp::ModuleExitCodeMessage::ModuleExitCode BodyHubModule::body() { 
    FIFOQueue fifo;
    addDataStoreFor(7, fifo);

    while (getModuleStateAndWaitForRemainingTimeInTimeslice() == odcore::data::dmcp::ModuleStateMessage::RUNNING) {
        
        //Receive Data
        Container c = fifo.leave();
        SensorData sd = c.getData<SensorData>();

        //View Data
        cout << "-------------------------------------------------" << endl;
        cout << sd.toString() << endl;
        cout << " sent at " << c.getSentTimeStamp().getYYYYMMDD_HHMMSS() << endl;
        cout << " received at " << c.getReceivedTimeStamp().getYYYYMMDD_HHMMSS() << endl;
        cout << " processed at " << TimeStamp().getYYYYMMDD_HHMMSS() << endl;
        cout << "-------------------------------------------------" << endl;

        //Persist Data

    }
    
return odcore::data::dmcp::ModuleExitCodeMessage::OKAY;
}