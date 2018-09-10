#include "GMPolyData.h"


#include "vtkCellArray.h"
#include "vtkFieldData.h"
#include "vtkInformation.h"
#include "vtkInformationVector.h"
#include "vtkObjectFactory.h"
#include "vtkPolyData.h"
//#include "vtkPolyDataReader.h"

#include <ctype.h>
#include <sys/stat.h>

vtkStandardNewMacro(GMPolyData);

GMPolyData::GMPolyData(void)
{
}

GMPolyData::~GMPolyData(void)
{
}

	std::string GMPolyData::GetID()
		{
		
			return _ID;
	}

	void GMPolyData::SetDBID(int id)
	{
		db_id = id;
	}
	int GMPolyData::GetDBID()
	{
		return db_id;
	}
	void GMPolyData::SetID(std::string str)
	{
		_ID = str;
	}

	int GMPolyData::GetGeometryType()
	{
		return _GeometryType;
	}
	void GMPolyData::SetGeometryType(int i)
	{_GeometryType = i;};
