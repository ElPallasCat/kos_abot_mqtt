/*************************************************************************
 *** FORTE Library Element
 ***
 *** This file was generated using the 4DIAC FORTE Export Filter V1.0.x NG!
 ***
 *** Name: AB_BACKWORD
 *** Description: Alphabot motors forward command
 *** Version:
***     1.0: 2023-01-19/ -  - 
 *************************************************************************/

#ifndef _AB_BACKWORD_H_
#define _AB_BACKWORD_H_

#include "basicfb.h"
#include "forte_bool.h"
#include "forte_uint.h"
#include "forte_array_at.h"


class FORTE_AB_BACKWORD: public CBasicFB {
  DECLARE_FIRMWARE_FB(FORTE_AB_BACKWORD)

private:
  static const CStringDictionary::TStringId scm_anDataInputNames[];
  static const CStringDictionary::TStringId scm_anDataInputTypeIds[];
  
  static const CStringDictionary::TStringId scm_anDataOutputNames[];
  static const CStringDictionary::TStringId scm_anDataOutputTypeIds[];
  
  static const TEventID scm_nEventREQID = 0;
  
   static const TDataIOID scm_anEIWith[];
  static const TForteInt16 scm_anEIWithIndexes[];
  static const CStringDictionary::TStringId scm_anEventInputNames[];
  
  static const TEventID scm_nEventCNFID = 0;
  
   static const TDataIOID scm_anEOWith[]; 
  static const TForteInt16 scm_anEOWithIndexes[];
  static const CStringDictionary::TStringId scm_anEventOutputNames[];
  

  static const SFBInterfaceSpec scm_stFBInterfaceSpec;

virtual void setInitialValues();
  CIEC_BOOL &st_QI() {
    return *static_cast<CIEC_BOOL*>(getDI(0));
  }
  
  CIEC_UINT &st_DURATION() {
    return *static_cast<CIEC_UINT*>(getDI(1));
  }
  
  CIEC_BOOL &st_QO() {
    return *static_cast<CIEC_BOOL*>(getDO(0));
  }
  


  static const TForteInt16 scm_nStateSTART = 0;
  
  void enterStateSTART(void);

  virtual void executeEvent(int pa_nEIID);

  FORTE_BASIC_FB_DATA_ARRAY(1, 2, 1, 0, 0);

public:
  FORTE_AB_BACKWORD(CStringDictionary::TStringId pa_nInstanceNameId, CResource *pa_poSrcRes) :
      CBasicFB(pa_poSrcRes, &scm_stFBInterfaceSpec, pa_nInstanceNameId, nullptr, m_anFBConnData, m_anFBVarsData) {
  };

  virtual ~FORTE_AB_BACKWORD() = default;
};

#endif // _AB_BACKWORD_H_


