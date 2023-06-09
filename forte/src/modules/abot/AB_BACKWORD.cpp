/*************************************************************************
 *** FORTE Library Element
 ***
 *** This file was generated using the 4DIAC FORTE Export Filter V1.0.x NG!
 ***
 *** Name: AB_BACKWORD
 *** Description: Alphabot motors forward command
 *** Version:
***     1.0: 2023-01-19/-  - 
 *************************************************************************/

#include "AB_BACKWORD.h"
#ifdef FORTE_ENABLE_GENERATED_SOURCE_CPP
#include "AB_BACKWORD_gen.cpp"
#endif

#include "gpioutils.h"


DEFINE_FIRMWARE_FB(FORTE_AB_BACKWORD, g_nStringIdAB_BACKWORD)

const CStringDictionary::TStringId FORTE_AB_BACKWORD::scm_anDataInputNames[] = {g_nStringIdQI, g_nStringIdDURATION};

const CStringDictionary::TStringId FORTE_AB_BACKWORD::scm_anDataInputTypeIds[] = {g_nStringIdBOOL, g_nStringIdUINT};

const CStringDictionary::TStringId FORTE_AB_BACKWORD::scm_anDataOutputNames[] = {g_nStringIdQO};

const CStringDictionary::TStringId FORTE_AB_BACKWORD::scm_anDataOutputTypeIds[] = {g_nStringIdBOOL};

const TDataIOID FORTE_AB_BACKWORD::scm_anEIWith[] = {0, 1, 255};
const TForteInt16 FORTE_AB_BACKWORD::scm_anEIWithIndexes[] = {0};
const CStringDictionary::TStringId FORTE_AB_BACKWORD::scm_anEventInputNames[] = {g_nStringIdREQ};

const TDataIOID FORTE_AB_BACKWORD::scm_anEOWith[] = {0, 255};
const TForteInt16 FORTE_AB_BACKWORD::scm_anEOWithIndexes[] = {0};
const CStringDictionary::TStringId FORTE_AB_BACKWORD::scm_anEventOutputNames[] = {g_nStringIdCNF};


const SFBInterfaceSpec FORTE_AB_BACKWORD::scm_stFBInterfaceSpec = {
  1, scm_anEventInputNames, scm_anEIWith, scm_anEIWithIndexes,
  1, scm_anEventOutputNames, scm_anEOWith, scm_anEOWithIndexes,
  2, scm_anDataInputNames, scm_anDataInputTypeIds,
  1, scm_anDataOutputNames, scm_anDataOutputTypeIds,
  0, nullptr
};

void FORTE_AB_BACKWORD::setInitialValues() {
}


void FORTE_AB_BACKWORD::enterStateSTART(void) {
  m_nECCState = scm_nStateSTART;
}


void FORTE_AB_BACKWORD::executeEvent(int pa_nEIID){
  bool bTransitionCleared;
  do {
    bTransitionCleared = true;
    switch(m_nECCState) {
      case scm_nStateSTART:
	      unsigned int duration = DURATION();
          ABotEngines::instance()->back(duration); 
          bTransitionCleared  = false; //no transition cleared
        break;
      default:
        DEVLOG_ERROR("The state is not in the valid range! The state value is: %d. The max value can be: 1.", m_nECCState.operator TForteUInt16 ());
        m_nECCState = 0; // 0 is always the initial state
        break;
    }
    pa_nEIID = cg_nInvalidEventID; // we have to clear the event after the first check in order to ensure correct behavior
  } while(bTransitionCleared);
}


