////////////////////////////////////////////////////////////////////////
// \file DUNEOpDetResponse.h
//
// \brief service containing information about the response of optical detectors in DUNE
//
// \author ahimmel@phy.duke.edu
//
////////////////////////////////////////////////////////////////////////

#ifndef DUNE_OPDET_RESPONSE_H
#define DUNE_OPDET_RESPONSE_H

// LArSoft includes
#include "lardataobj/Simulation/SimPhotons.h"
#include "larana/OpticalDetector/OpDetResponseInterface.h"
#include "dune/OpticalDetector/DUNEOpDetResponseInterface.h"



namespace opdet
{
  class DUNEOpDetResponse : public opdet::DUNEOpDetResponseInterface {
    public:

      DUNEOpDetResponse(fhicl::ParameterSet const& pset, art::ActivityRegistry& reg);
      ~DUNEOpDetResponse() throw();

      // virtual bool detectedLite(int OpDet, int &newOpChannel, int& hardwareChannel) const;
      //bool DUNEOpDetResponse::detectedLite(int OpDet, int &newOpChannel, int& hardwareChannel) const
      /*
      virtual bool detectedLite(int OpDet, int &newOpChannel, int& hardwareChannel) const
      {
        return doDetectedLite( OpDet, newOpChannel, hardwareChannel);
      }*/



    private:

      virtual void doReconfigure(fhicl::ParameterSet const& p);

      virtual int  doNOpChannels() const;
      virtual bool doDetected(int OpDet, const sim::OnePhoton& Phot, int &newOpChannel) const;
      virtual bool doDetectedLite(int OpDet, int &newOpChannel) const;
      virtual bool doDetectedLite(int OpDet, int &newOpChannel, int& hardwareChannel) const;

      float fQE;                     // Quantum efficiency of tube

      float fWavelengthCutLow;       // Sensitive wavelength range
      float fWavelengthCutHigh;      //

      bool fLightGuideAttenuation;   // Flag to turn on position-dependent sensitivity
      double lambdaShort;
      double lambdaLong;
      double fracShort;
      double fracLong;


      std::string fChannelConversion;
      bool fFullSimChannelConvert;   // Flag to conver detector->electronics channels in full optical sim
      bool fFastSimChannelConvert;   // Flag to conver detector->electronics channels in fast optical sim

      int fLongAxis;                 // 0 = x, 1 = y, 2 = z

  }; // class DUNEOpDetResponse


} //namespace opdet


DECLARE_ART_SERVICE_INTERFACE_IMPL(opdet::DUNEOpDetResponse, opdet::DUNEOpDetResponseInterface, LEGACY)

#endif //OPDET_RESPONSE_DUNE_H
