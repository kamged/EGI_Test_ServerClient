#include "TestByteStream.h"

/// <summary>
/// Example values for the EGI parameters
/// </summary>
TestByteStream::TestByteStream()
{	
	ildl_types.Heading.setValue("Heading", 100);
	ildl_types.IAS.setValue("IAS", 850);
	ildl_types.TAS.setValue("TAS", 650);
	ildl_types.P_Att.setValue("P_Att", 90);
	ildl_types.R_Att.setValue("R_Att", 45);
	ildl_types.Y_Att.setValue("Y_Att", 10);
	ildl_types.RPrsntGndSpd.setValue("GS", 100);
	ildl_types.VerticalSpd.setValue("VSI", 2400);
}