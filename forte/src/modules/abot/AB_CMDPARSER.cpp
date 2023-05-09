/*************************************************************************
 *** FORTE Library Element
 ***
 *** This file was generated using the 4DIAC FORTE Export Filter V1.0.x NG!
 ***
 *** Name: AB_CMDPARSER
 *** Description: Basic FB with empty ECC
 *** Version:
***     1.0: 2023-01-19/ -  - 
 *************************************************************************/

#include "AB_CMDPARSER.h"
#ifdef FORTE_ENABLE_GENERATED_SOURCE_CPP
#include "AB_CMDPARSER_gen.cpp"
#endif

#include "rapidjson/include/rapidjson/document.h"
#include "rapidjson/include/rapidjson/reader.h"
//#include "rapidjson/include/rapidjson/filereadstream.h"
#include <fstream>


DEFINE_FIRMWARE_FB(FORTE_AB_CMDPARSER, g_nStringIdAB_CMDPARSER)

const CStringDictionary::TStringId FORTE_AB_CMDPARSER::scm_anDataInputNames[] = {g_nStringIdQI, g_nStringIdSCMD};

const CStringDictionary::TStringId FORTE_AB_CMDPARSER::scm_anDataInputTypeIds[] = {g_nStringIdBOOL, g_nStringIdSTRING};

const CStringDictionary::TStringId FORTE_AB_CMDPARSER::scm_anDataOutputNames[] = {g_nStringIdQO, g_nStringIdCMD, g_nStringIdDURATION};

const CStringDictionary::TStringId FORTE_AB_CMDPARSER::scm_anDataOutputTypeIds[] = {g_nStringIdBOOL, g_nStringIdUINT, g_nStringIdUINT};

const TDataIOID FORTE_AB_CMDPARSER::scm_anEIWith[] = {0, 1, 255};
const TForteInt16 FORTE_AB_CMDPARSER::scm_anEIWithIndexes[] = {0};
const CStringDictionary::TStringId FORTE_AB_CMDPARSER::scm_anEventInputNames[] = {g_nStringIdREQ};

const TDataIOID FORTE_AB_CMDPARSER::scm_anEOWith[] = {0, 1, 2, 255};
const TForteInt16 FORTE_AB_CMDPARSER::scm_anEOWithIndexes[] = {0};
const CStringDictionary::TStringId FORTE_AB_CMDPARSER::scm_anEventOutputNames[] = {g_nStringIdCNF};


const SFBInterfaceSpec FORTE_AB_CMDPARSER::scm_stFBInterfaceSpec = {
  1, scm_anEventInputNames, scm_anEIWith, scm_anEIWithIndexes,
  1, scm_anEventOutputNames, scm_anEOWith, scm_anEOWithIndexes,
  2, scm_anDataInputNames, scm_anDataInputTypeIds,
  3, scm_anDataOutputNames, scm_anDataOutputTypeIds,
  0, nullptr
};

void FORTE_AB_CMDPARSER::setInitialValues() {
}


void FORTE_AB_CMDPARSER::enterStateSTART(void) {
  m_nECCState = scm_nStateSTART;
}


void FORTE_AB_CMDPARSER::executeEvent(int pa_nEIID){
  bool bTransitionCleared;
  do {
    bTransitionCleared = true;
    switch(m_nECCState) {
      case scm_nStateSTART:

	auto source = st_SCMD().getValue();
	st_QO() = false;

	rapidjson::StringStream sourceStream(source);
	rapidjson::Document doc;
	doc.ParseStream(sourceStream);

	if (doc.IsObject())
		if (doc.HasMember(param))
			if (doc[param].IsString())
			{
			  switch (std::string(doc[param].GetString())) {
			    case "stop":
				st_CMD() = 0;
				st_QO() = true;
				break;
			    case "forward":
				st_CMD() = 1;
				st_QO() = true;
				break;
			    case "left":
				st_CMD() = 2;
				st_QO() = true;
				break;
			    case "right":
				st_CMD() = 3;
				st_QO() = true;
				break;
			  }	
			}

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


