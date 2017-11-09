#pragma once
#include <vector>
#include <QPoint>
#include <Eigen/Dense>
using namespace std;
using namespace Eigen;

class RBF
{
public:
	RBF();
	RBF(vector<QPoint> &p_points, vector<QPoint> &q_points, int u);
	~RBF();

public:
	QPoint p2q(QPoint p);						//����RBF�㷨��p��ӳ�䵽�ĵ�

private:
	double getDistance(QPoint p, QPoint q);		//����2������ƽ��

	void calculateDistanceMartix();				//��������2��p���ݵ�ľ����γɵľ���

	void calculateRi();							//����ÿ��p���ݵ��Ӧ��Rֵ

	void calculateAi();							//��������Է������е�ax,ay

private:
	double u_;						//���㹫ʽ�е�һ������

	int size_;						//�������ݵ�Ե�����

	vector<QPoint> p_points_;		//��������ݵ��
	vector<QPoint> q_points_;

	double *d_;						//�������
									//(pi,pj��2������ƽ��)d(i,j)^2=d_[i*size+j]=d_[j*size+i]
									//d(i,i)^2=d_[i*size+i]=0;
		
	double *r_;						//Ri����(�洢ÿ��p���ݵ��Ӧ��Rֵ)

	VectorXd Ax_;					//���Է�����Ľ�
	VectorXd Ay_;
};
