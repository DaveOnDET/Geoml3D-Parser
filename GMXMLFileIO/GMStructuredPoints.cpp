#include "GMStructuredPoints.h"

#include "vtkCellArray.h"
#include "vtkFieldData.h"
#include "vtkInformation.h"
#include "vtkInformationVector.h"
#include "vtkObjectFactory.h"
#include "vtkPolyData.h"
#include "vtkCharArray.h"
//#include "vtkStructuredPointsReader.h"
#include <ctype.h>
#include <sys/stat.h>

vtkStandardNewMacro(GMStructuredPoints);

GMStructuredPoints::GMStructuredPoints(void)
{
	_TransformMatrix = 0;
}


GMStructuredPoints::~GMStructuredPoints(void)
{
	if(_TransformMatrix)
		_TransformMatrix->Delete();
}
/*
GMStructuredPoints* GMStructuredPoints::New()
{
	return new GMStructuredPoints;
}
*/

vtkMatrix4x4*  GMStructuredPoints::GetTransformMatrix()
{
	return _TransformMatrix;
}
	void GMStructuredPoints::CreateTransformMatrix() 
	{
		_TransformMatrix = vtkMatrix4x4::New();
	}
	
	std::string GMStructuredPoints::GetID()
		{
			return _ID;
	}
	void GMStructuredPoints::SetID(std::string str)
	{
		_ID = str;
	}

	void GMStructuredPoints::ReadFile(char* filename)
	{
		/*vtkStructuredPointsReader * reader = vtkStructuredPointsReader::New();

		reader->SetFileName(filename);
		reader->SetOutput(this);
		reader->Update();

		this->SetID("new_Geo_Grid_ID_1");
		reader->Delete();*/
	}
	
