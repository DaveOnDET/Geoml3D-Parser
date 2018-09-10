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

	//-------------�ǵ��������Ԫ���ϡ���ǵ������ά��Ϊ (Ni, Nj, Nk)����������������Ԫ����Ϊ (Ni * Nj * Nk)���˼�Ϊ����Ԫ��������Ԫ�ص���Ŀ��
	//	��I����Ϊ���С���J����Ϊ���С���K����Ϊ���㡱����Ԫ�ذ���-��-�����ȵ�˳��˳�μ�¼��Ԫ��λ�á����ȼ�¼����ֵΪ(Xi,0,0)������XiΪ��������������[0,Ni)������Ԫ�����ż�¼����ֵΪ(Xi,1,0)����Ԫ�����������ż�¼����ֵΪ(Xi,0,1)����Ԫ����������¼����ֵΪ(Xi,Nj - 1, Nk - 1)����Ԫ��

	//�ǵ��������������Ԫ����Ԫ�س��ֵĴ���Ϊ (Ni * Nj * Nk)��
	//	�ǵ�������ÿ����������Ԫ�����䶥��4���ǵ㼰����4���ǵ���ȷ��������Щ�ǵ��λ��Pillar���ϣ���˽����¼���ǵ��Z����ֵ�����ڶ�ӦPillar���Ͼ���Pillar���׶���ľ��뼴��ȷ���ǵ��λ�á�
	//	��������ϵI-J-K��ƽ�Ƹ���Ԫ��ʹ��һ������ԭ���غϣ���ʹ�ù��ö����������ֱ����Ӧ����������������غϣ�Ȼ��ֱ��Ը�������ĳ���Ϊ��λ���ȣ�����ԼǸ���Ԫ��8���ǵ������Ϊ(0,0,0)��(1,0,0)��(0,1,0)��(1,1,0)��(0,0,1)��(1,0,1)��(0,1,1)��(1,1,1)����Ԫ�ذ���˳���¼���ǵ�ĺ��θ߳�ֵ��Z���꣩����Pillar���׶���ľ��롣������Ԫ������ֵΪ(i,j,k)������i,j,k��Ϊ��0��ʼ������ֵ����������8���ǵ��������Ӧ��Pillar�ߵ�����ֵ�ֱ�Ϊ��(i,j)��(i + 1,j)��(i,j + 1)��(i + 1,j + 1)��(i,j)��(i + 1,j)��(i,j + 1)��(i + 1,j + 1)��</documentation>
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
		int index = nj*(Dimension[0]+1)+ ni;//pillarÿ��ÿ�зֱ���Dimension[0]+1��Dimension[1]+1��
		Pillar &v = Pillars[index];

		HeadPos[0] = v.HeadPos[0];
		HeadPos[1] = v.HeadPos[1];
		HeadPos[2] = v.HeadPos[2];

		TailPos[0] = v.TailPos[0];
		TailPos[1] = v.TailPos[1];
		TailPos[2] = v.TailPos[2];
	}

	//-------------�ǵ������Pillar����ɵ����顣Pillar������K����չ��ֱ�߶Ρ�
	//	��ýǵ������ά��Ϊ (Ni, Nj, Nk)������I����Ϊ���С�����J����Ϊ���С����������Pillar�߿ɼ�Ϊ (Nj + 1) �С�(Ni + 1) �У�������Ϊ (Nj + 1) * (Ni + 1)��
	//	��Ԫ���ԡ��С����ȵķ�ʽ��¼���е�Pillar�ߣ����ȼ�¼��0�а����ĵ�0������Ni�еĹ� (Ni + 1) ��Pillar�ߣ�Ȼ���¼��1�а����ĵ�0������Ni�еĹ� (Ni + 1) ��Pillar�ߣ�����������¼��Nj�а����ĵ�0������Ni�еĹ� (Ni + 1) ��Pillar�ߡ�
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
		//�����ǰ����ṹ
		this->Initialize();
		//�����µ� ������
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
			//�ϲ�����������
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
		//��Ԫ
		vtkNew<vtkCellArray> cells;
		cells->Allocate(ncell);
		int cnt = 0;
		int pillarDimI = Dimension[0] + 1;
		for (int j = 0; j < Jdim; j++){
			for (int i = 0; i < Idim; i++){
				//����ָ����������Ԫ��4��pillar
				int pillarIndex0 = j*pillarDimI + i;
				int pillarIndex1 = pillarIndex0 + 1;
				int pillarIndex2 = pillarIndex1 + pillarDimI;
				int pillarIndex3 = pillarIndex2 - 1;
				//��������Ԫ��8���ǵ�
				double cell[8];
				this->GetCell(i, j, k, cell);
				double pos[3];
				//��������4����
				this->calcCornerPoint(pillarIndex0, cell[0], pos);
				pts->InsertNextPoint(pos);
				this->calcCornerPoint(pillarIndex1, cell[1], pos);
				pts->InsertNextPoint(pos);
				this->calcCornerPoint(pillarIndex2, cell[2], pos);
				pts->InsertNextPoint(pos);
				this->calcCornerPoint(pillarIndex3, cell[3], pos);
				pts->InsertNextPoint(pos);
				//���������ĸ���
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
		//�����������
		if (!CellPropertyData.empty())
			out->GetCellData()->SetScalars(CellPropertyData.front());
	}

	void GMCornerPointGrid::calcCornerPoint(int pillarIndex, double depth, double pos[3])
	{
		Pillar&pillar = Pillars[pillarIndex];
		double vec[3];
		//head����tail
		vtkMath::Subtract(pillar.TailPos, pillar.HeadPos, vec);
		double len = vtkMath::Normalize(vec);
		bool isEle = this->GetZValueType() == "elevation";
		double offset[3];
		depth = isEle ? ((pillar.HeadPos[2] - depth) / (pillar.HeadPos[2] - pillar.TailPos[2])*len) : depth;
		vtkMath::MultiplyScalar(vec, depth);
		vtkMath::Add(pillar.HeadPos, vec, pos);
	}
