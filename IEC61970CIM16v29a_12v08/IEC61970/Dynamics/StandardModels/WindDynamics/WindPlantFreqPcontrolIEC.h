///////////////////////////////////////////////////////////
//  WindPlantFreqPcontrolIEC.h
//  Implementation of the Class WindPlantFreqPcontrolIEC
//  Original author: civanov
///////////////////////////////////////////////////////////

#ifndef WINDPLANTFREQPCONTROLIEC_H
#define WINDPLANTFREQPCONTROLIEC_H

#include "IEC61970/Base/Domain/PU.h"
#include "IEC61970/Base/Domain/Float.h"
#include "IEC61970/Base/Domain/Seconds.h"
#include "IEC61970/Base/Core/IdentifiedObject.h"
#include "IEC61970/Dynamics/StandardModels/WindDynamics/WindPlantIEC.h"

namespace IEC61970
{
	namespace Dynamics
	{
		namespace StandardModels
		{
			namespace WindDynamics
			{
				/**
				 * Frequency and active power controller model.
				 * 
				 * Reference: IEC Standard 61400-27-1 Annex D.
				 */
				class WindPlantFreqPcontrolIEC : public IEC61970::Base::Core::IdentifiedObject
				{

				public:
					WindPlantFreqPcontrolIEC();
					virtual ~WindPlantFreqPcontrolIEC();
					/**
					 * Maximum ramp rate of <i>p</i><sub>WTref</sub> request from the plant controller
					 * to the wind turbines (<i>dp</i><sub>refmax</sub>). It is case dependent
					 * parameter.
					 */
					IEC61970::Base::Domain::PU dprefmax;
					/**
					 * Minimum (negative) ramp rate of <i>p</i><sub>WTref</sub> request from the plant
					 * controller to the wind turbines (<i>dp</i><sub>refmin</sub>). It is project
					 * dependent parameter.
					 */
					IEC61970::Base::Domain::PU dprefmin;
					/**
					 * Maximum positive ramp rate for wind plant power reference
					 * (<i>dp</i><sub>WPrefmax</sub>). It is project dependent parameter.
					 */
					IEC61970::Base::Domain::PU dpwprefmax;
					/**
					 * Maximum negative ramp rate for wind plant power reference
					 * (<i>dp</i><sub>WPrefmin</sub>). It is project dependent parameter.
					 */
					IEC61970::Base::Domain::PU dpwprefmin;
					/**
					 * Plant P controller integral gain (<i>K</i><sub>IWPp</sub>). It is project
					 * dependent parameter.
					 */
					IEC61970::Base::Domain::Float kiwpp;
					/**
					 * Maximum PI integrator term (<i>K</i><sub>IWPpmax</sub>). It is project
					 * dependent parameter.
					 */
					IEC61970::Base::Domain::PU kiwppmax;
					/**
					 * Minimum PI integrator term (<i>K</i><sub>IWPpmin</sub>). It is project
					 * dependent parameter.
					 */
					IEC61970::Base::Domain::PU kiwppmin;
					/**
					 * Plant P controller proportional gain (<i>K</i><sub>PWPp</sub>). It is project
					 * dependent parameter.
					 */
					IEC61970::Base::Domain::Float kpwpp;
					/**
					 * Power reference gain (<i>K</i><sub>WPpref</sub>). It is project dependent
					 * parameter.
					 */
					IEC61970::Base::Domain::PU kwppref;
					/**
					 * Maximum <i>p</i><sub>WTref</sub> request from the plant controller to the wind
					 * turbines (<i>p</i><sub>refmax</sub>). It is project dependent parameter.
					 */
					IEC61970::Base::Domain::PU prefmax;
					/**
					 * Minimum <i>p</i><sub>WTref</sub> request from the plant controller to the wind
					 * turbines (<i>p</i><sub>refmin</sub>). It is project dependent parameter.
					 */
					IEC61970::Base::Domain::PU prefmin;
					/**
					 * Lead time constant in reference value transfer function
					 * (<i>T</i><sub>pft</sub>). It is project dependent parameter.
					 */
					IEC61970::Base::Domain::Seconds tpft;
					/**
					 * Lag time constant in reference value transfer function (<i>T</i><sub>pfv</sub>).
					 * It is project dependent parameter.
					 */
					IEC61970::Base::Domain::Seconds tpfv;
					/**
					 * Filter time constant for frequency measurement (<i>T</i><sub>WPffiltp</sub>).
					 * It is project dependent parameter.
					 */
					IEC61970::Base::Domain::Seconds twpffiltp;
					/**
					 * Filter time constant for active power measurement (<i>T</i><sub>WPpfiltp</sub>).
					 * It is project dependent parameter.
					 */
					IEC61970::Base::Domain::Seconds twppfiltp;
					/**
					 * Wind plant model with which this wind plant frequency and active power control
					 * is associated.
					 */
					IEC61970::Dynamics::StandardModels::WindDynamics::WindPlantIEC *WindPlantIEC;

				};

			}

		}

	}

}
#endif // WINDPLANTFREQPCONTROLIEC_H
