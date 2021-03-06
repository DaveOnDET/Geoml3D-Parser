#include "GMCornerPointGrid.h"
#include "GMUnstructuredGrid.h"
#include "vtkNew.h"
#include "vtkCellArray.h"
#include "vtkFieldData.h"
#include "vtkInformation.h"
#include "vtkInformationVector.h"
#include "vtkUnstructuredGrid.h"
#include "vtkObjectFactory.h"
#include "vtkMergeCells.h"
#include "vtkAppendFilter.h"
#include "vtkPolyData.h"
#include "vtkCellData.h"
#include "vtkCharArray.h"
#include "vtkMath.h"
//#include "vtkUnstructuredGridreader.h"

#include <ctype.h>
#include <sys/stat.h>

vtkStandardNewMacro(GMCornerPointGrid);

GMCornerPointGrid::GMCornerPointGrid(void)
{
	rendermode=2;
	ZValueType = "elevation";
}


GMCornerPointGrid::~GMCornerPointGrid(void)
{
	for(int i = 0; i < CellPropertyData.size(); i++)
		CellPropertyData[i]->Delete();
 }
/*
GMCornerPointGrid* GMCornerPointGrid::New(void)
{
	return new GMCornerPointGrid;
}
*/

	std::string GMCornerPointGrid::GetID()
		{
			return _ID;
	}
	void GMCornerPointGrid::SetID(std::string str)
	{
		_ID = str;
	}

	//--------
	std::string  GMCornerPointGrid:: GetZValueType()
	{
		return ZValueType;
	}
	 
	void GMCornerPointGrid::SetZValueType(std::string t)
	{

		  ZValueType=t;
	}

	//-------------角点网格的体元集合。设角点网格的维度为 (Ni, Nj, Nk)，则其所包含的体元总数为 (Ni * Nj * Nk)，此即为本子元素所包含元素的数目。
	//	以I方向为“行”、J方向为“列”、K方向为“层”，本元素按行-列-层优先的顺序顺次记录体元的位置。即先记录索引值为(Xi,0,0)（其中Xi为整数，属于区间[0,Ni)）的体元，接着记录索引值为(Xi,1,0)的体元，……，接着记录索引值为(Xi,0,1)的体元，……最后记录索引值为(Xi,Nj - 1, Nk - 1)的体元。

	//角点网格的六面体体元。本元素出现的次数为 (Ni * Nj * Nk)。
	//	角点网格中每个六面体体元都由其顶面4个角点及底面4个角点来确定。而这些角点均位于Pillar线上，因此仅需记录各角点的Z坐标值或其在对应Pillar线上距离Pillar线首顶点的距离即可确定角点的位置。
	//	若在坐标系I-J-K内平移该体元，使其一顶点与原点重合，并使得过该顶点的三条棱分别与对应的坐标轴的正方向重合，然后分别以该三条棱的长度为单位长度，则可以记该体元的8个角点的坐标为(0,0,0)、(1,0,0)、(0,1,0)、(1,1,0)、(0,0,1)、(1,0,1)、(0,1,1)、(1,1,1)。本元素按此顺序记录各角点的海拔高程值（Z坐标）或与Pillar线首顶点的距离。若记体元的索引值为(i,j,k)（其中i,j,k均为从0开始的索引值），则上述8个角点各自所对应的Pillar线的索引值分别为：(i,j)、(i + 1,j)、(i,j + 1)、(i + 1,j + 1)、(i,j)、(i + 1,j)、(i,j + 1)、(i + 1,j + 1)。</documentation>
	void GMCornerPointGrid::AddCell(double cell[8],char cellv)
	{
		for(int i = 0; i < 8; i++)
			Cells.push_back(cell[i]);

		ValidCells.push_back(cellv);
	}
	void GMCornerPointGrid::GetCell(int index,double cell[8])
	{
		for(int i = 0; i < 8; i++)
		{
			cell[i] = 0 ;
			
		 
		}
		if(index*8+7 < Cells.size())
		for(int i = 0; i < 8; i++)
		{
			 
				cell[i] = Cells[index*8+i];
		}
	}
	void GMCornerPointGrid::GetCell(int ni,int nj,int nk,double cell[8])
	{
		for(int i = 0; i < 8; i++)
		{
			cell[i] = 0 ;


		}

		int index = nk*Dimension[1]*Dimension[0] + nj*Dimension[0]+ ni;
		
			
			if(index*8+7 < Cells.size())		
			for(int i = 0; i < 8; i++)
			{

				cell[i] = Cells[index*8+i];
			}
	}

	//-------------------------
	void GMCornerPointGrid::GetPillar(int index,double HeadPos[3],	double TailPos[3])
	{
		Pillar &v = Pillars[index];
		HeadPos[0] = v.HeadPos[0];
		HeadPos[1] = v.HeadPos[1];
		HeadPos[2] = v.HeadPos[2];

		TailPos[0] = v.TailPos[0];
		TailPos[1] = v.TailPos[1];
		TailPos[2] = v.TailPos[2];
	}
	void GMCornerPointGrid::GetPillar(int ni,int nj,double HeadPos[3],	double TailPos[3])
	{
		int index = nj*(Dimension[0]+1)+ ni;//pillar每行每列分别有Dimension[0]+1和Dimension[1]+1个
		Pillar &v = Pillars[index];

		HeadPos[0] = v.HeadPos[0];
		HeadPos[1] = v.HeadPos[1];
		HeadPos[2] = v.HeadPos[2];

		TailPos[0] = v.TailPos[0];
		TailPos[1] = v.TailPos[1];
		TailPos[2] = v.TailPos[2];
	}

	//-------------角点网格的Pillar线组成的数组。Pillar线是沿K轴延展的直线段。
	//	设该角点网格的维度为 (Ni, Nj, Nk)，并以I方向为“行”、以J方向为“列”，则网格的Pillar线可记为 (Nj + 1) 行、(Ni + 1) 列，总条数为 (Nj + 1) * (Ni + 1)。
	//	本元素以“行”优先的方式记录所有的Pillar线，即先记录第0行包含的第0列至第Ni列的共 (Ni + 1) 条Pillar线，然后记录第1行包含的第0列至第Ni列的共 (Ni + 1) 条Pillar线，……，最后记录第Nj行包含的第0列至第Ni列的共 (Ni + 1) 条Pillar线。
	void GMCornerPointGrid::AddPillar(double HeadPos[3],	double TailPos[3]) //
	{
		Pillar v ;

		v.HeadPos[0] = HeadPos[0];
		v.HeadPos[1] = HeadPos[1];
		v.HeadPos[2] = HeadPos[2];


		v.TailPos[0] = TailPos[0];
		v.TailPos[1] = TailPos[1];
		v.TailPos[2] = TailPos[2];

		Pillars.push_back(v);
	}

	//---------------------------
	void GMCornerPointGrid::UpdateGrid()
	{
		//清除当前网格结构
		this->Initialize();
		//创建新的 网格体
		int nDataset =Dimension[2];
		if (nDataset == 0)
			return;
		int nLayerCell = Dimension[0] * Dimension[1];
		int nTotalCells = nDataset*nLayerCell;
		//vtkNew<vtkAppendFilter> merger;
		//merger->SetMergePoints(1);
		vtkNew<vtkMergeCells> merger;
		vtkNew<vtkUnstructuredGrid> GridData;
		merger->SetTotalNumberOfDataSets(nDataset);
		merger->SetTotalNumberOfPoints(nTotalCells * 8 - (nDataset - 2)*(Dimension[0]-2) * (Dimension[1]-2)*4);
		merger->SetTotalNumberOfCells(nTotalCells);
		merger->SetMergeDuplicatePoints(1);
		merger->SetUnstructuredGrid(GridData.Get());
		merger->MergeDuplicatePointsOn();
		merger->SetPointMergeTolerance(0.01);
		for (int k = 0; k <nDataset; k++){
			vtkNew<vtkUnstructuredGrid> kGrid;
			this->MakeKthGrid(k, kGrid.Get());	
			double* test = kGrid->GetBounds();
			//合并到整个网格
			merger->MergeDataSet(kGrid.Get());
		}
		merger->Finish();
		//this->ShallowCopy(merger->GetOutput());
		this->ShallowCopy(GridData.Get());
	}

	void   GMCornerPointGrid::AddCellPropertyData(vtkDataArray*v)
	{
		CellPropertyData.push_back(v);

	}

	vtkDataArray* GMCornerPointGrid::GetCellPropertyData(int i)
	{
		if(i <  CellPropertyData.size())
		return CellPropertyData[i];

		return 0;
	}

	void GMCornerPointGrid::GetDimension(int dimension[3])
	{
		for(int i =0;i < 3; i++)
			dimension[i] = Dimension[i];
	}

	void  GMCornerPointGrid::SetDimension(int dimension[3])
	{
		for(int i =0;i < 3; i++)
			Dimension[i] = dimension[i];
	}
	int   GMCornerPointGrid::GetCountOfCellPropertyData()
	{
		return CellPropertyData.size();
	}

	int   GMCornerPointGrid::GetCellCount()
	{
		return Cells.size()/8;
	}
	 
	int   GMCornerPointGrid::GetPillarCount()
	{
		return Pillars.size();
	}

	void GMCornerPointGrid::MakeKthGrid(int k, vtkUnstructuredGrid*out)
	{
		int Idim = Dimension[0];
		int Jdim = Dimension[1];
		int ncell = Idim*Jdim;
		vtkNew<vtkPoints> pts;
		pts->Allocate(ncell * 8);
		//单元
		vtkNew<vtkCellArray> cells;
		cells->Allocate(ncell);
		int cnt = 0;
		int pillarDimI = Dimension[0] + 1;
		for (int j = 0; j < Jdim; j++){
			for (int i = 0; i < Idim; i++){
				//计算指定索引网格单元的4个pillar
				int pillarIndex0 = j*pillarDimI + i;
				int pillarIndex1 = pillarIndex0 + 1;
				int pillarIndex2 = pillarIndex1 + pillarDimI;
				int pillarIndex3 = pillarIndex2 - 1;
				//计算网格单元的8个角点
				double cell[8];
				this->GetCell(i, j, k, cell);
				double pos[3];
				//计算上面4个点
				this->calcCornerPoint(pillarIndex0, cell[0], pos);
				pts->InsertNextPoint(pos);
				this->calcCornerPoint(pillarIndex1, cell[1], pos);
				pts->InsertNextPoint(pos);
				this->calcCornerPoint(pillarIndex2, cell[2], pos);
				pts->InsertNextPoint(pos);
				this->calcCornerPoint(pillarIndex3, cell[3], pos);
				pts->InsertNextPoint(pos);
				//计算下面四个点
				this->calcCornerPoint(pillarIndex0, cell[4], pos);
				pts->InsertNextPoint(pos);
				this->calcCornerPoint(pillarIndex1, cell[5], pos);
				pts->InsertNextPoint(pos);
				this->calcCornerPoint(pillarIndex2, cell[6], pos);
				pts->InsertNextPoint(pos);
				this->calcCornerPoint(pillarIndex3, cell[7], pos);
				pts->InsertNextPoint(pos);
				vtkNew<vtkIdList> ids;
				ids->SetNumberOfIds(8);
				for (int c = 0; c < 8; c++){
					ids->SetId(c, cnt++);
				}
				cells->InsertNextCell(ids.Get());
			}
		}
		//
		out->Initialize();
		out->SetPoints(pts.Get());
		out->SetCells(VTK_HEXAHEDRON,cells.Get());
		//添加属性数组
		if (!CellPropertyData.empty())
			out->GetCellData()->SetScalars(CellPropertyData.front());
	}

	void GMCornerPointGrid::calcCornerPoint(int pillarIndex, double depth, double pos[3])
	{
		Pillar&pillar = Pillars[pillarIndex];
		double vec[3];
		//head大于tail
		vtkMath::Subtract(pillar.TailPos, pillar.HeadPos, vec);
		double len = vtkMath::Normalize(vec);
		bool isEle = this->GetZValueType() == "elevation";
		double offset[3];
		depth = isEle ? ((pillar.HeadPos[2] - depth) / (pillar.HeadPos[2] - pillar.TailPos[2])*len) : depth;
		vtkMath::MultiplyScalar(vec, depth);
		vtkMath::Add(pillar.HeadPos, vec, pos);
	}
