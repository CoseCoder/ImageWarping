#pragma once
#include <vector>
#include <QPoint>
using namespace std;
class IDW
{
public:
	IDW();
	IDW(vector<QPoint> p_points, vector<QPoint> q_points, double u);
	~IDW();

public:
	QPoint p2q(QPoint p, bool simple);					//����IDW�㷨��p��ӳ�䵽�ĵ�
														//simpleΪtrue��ʾֱ�ӽ�ÿ���ֲ����ƺ���fi(x)�ı任����T����2�׵�λ����
														//simpleΪfalse��ʾ����ÿ���ֲ����ƺ���fi(x)�ı任����T

private:
	double getDistance(QPoint p, QPoint q);				//����2������ƽ��

	void calculateSum(QPoint p);						//�����i(x)=1/(di(x))^u�ĺ�

	void calculateT(QPoint p, int i);					//����ֲ����ƺ���fi(x)�ı任����T

	double getWi(QPoint p, int i);						//����ÿ�����ݵ�Ե�Ȩ��
		
	QPoint getFiPoint(QPoint p, int i, bool simple);	//����p���ھֲ����ƺ���fi(x)ӳ���ĵ�
														//simpleΪtrue��ʾֱ�ӽ��ֲ����ƺ���fi(x)�ı任����T����2�׵�λ����
														//simpleΪfalse��ʾ����ֲ����ƺ���fi(x)�ı任����T


private:
	double u_;						//���㹫ʽ�е�һ������

	double sum_;					//��i(x)=1/(di(x))^u�ĺ�

	double **t_;					//�洢ÿ�����ݵ�Զ�Ӧ�ı任����T
									//Ti=(t_[0][2*i],t_[0][2*i+1])
									//    (t_[1][2*i],t_[1][2*i+1])

	int size_;						//�������ݵ�Ե�����
								
	vector<QPoint> p_points_;		//��������ݵ��
	vector<QPoint> q_points_;

};