#pragma once
#include <QWidget>
#include <vector>
#include <QImage>
#include <QPainter>
#include <QtWidgets> 
#include <iostream>
#include "IDW.h"
#include "RBF.h"

using namespace std;

QT_BEGIN_NAMESPACE
class QImage;
class QPainter;
QT_END_NAMESPACE

class ImageWidget :
	public QWidget
{
	Q_OBJECT

public:
	ImageWidget(void);
	~ImageWidget(void);

protected:
	void paintEvent(QPaintEvent *paintevent);
	void mousePressEvent(QMouseEvent * event);
	void mouseMoveEvent(QMouseEvent * event);
	void mouseReleaseEvent(QMouseEvent * event);

	public slots:
	// File IO
	void Open();												// Open an image file, support ".bmp, .png, .jpg" format
	void Save();												// Save image to current file
	void SaveAs();												// Save image to another file

	// Image processing
	void Invert();												// Invert pixel value in image
	void Mirror(bool horizontal = false, bool vertical = true);		// Mirror image vertically or horizontally
	void TurnGray();											// Turn image to gray-scale map
	void Restore();												// Restore image to origin

	void Input();												//�������ݵ��
	void WarpingIDW();											//ͨ��IDW�㷨��ͼ��Ť��
	void WarpingRBF();											//ͨ��RBF�㷨��ͼ��Ť��

private:
	void FillHole();											//������Χ���������׷�

private:
	QImage		*ptr_image_;				// image 
	QImage		*ptr_image_backup_;
	QImage		*ptr_image_temp_;				 

	bool input_;							//��ʾ��ǰ�Ƿ����������ݵ�Ե�״̬

	vector<QPoint> p_points_;				//��������ݵ��
	vector<QPoint> q_points_;

	int current_;							//��ʾ��ǰ���������һ�����ݵ�
	
	bool **change_;							//��ʾŤ�����ͼ���ÿ�����ص��Ƿ��б��ı��
};

