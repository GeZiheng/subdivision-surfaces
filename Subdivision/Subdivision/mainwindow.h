#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QtWidgets/QMainWindow>
#include "ui_mainwindow.h"

class QLabel;
class QPushButton;
class QCheckBox;
class QRadioButton;
class QGroupBox;
class RenderingWidget;

class MainWindow : public QMainWindow
{
	Q_OBJECT

public:
	MainWindow(QWidget *parent = 0);
	~MainWindow();

private:
	void CreateActions();
	void CreateMenus();
	void CreateToolBars();
	void CreateStatusBars();
	void CreateGroupBoxes();

protected:
	void keyPressEvent(QKeyEvent *e);
	void keyReleaseEvent(QKeyEvent *e);

	public slots:
	void ShowMeshInfo(int npoint, int nedge, int nface);
	void OpenFile();
	void ShowAbout();

private:
	Ui::MainWindowClass ui;

	// basic
	QMenu							*menu_file_;
	QMenu							*menu_edit_;
	QToolBar						*toolbar_file_;
	QToolBar						*toolbar_edit_;
	QToolBar						*toolbar_basic_;
	QGroupBox						*groupbox_render_;
	QGroupBox						*groupbox_subdivide_;
	QSlider							*slider_;

	// basic
	QAction							*action_new_;
	QAction							*action_open_;
	QAction							*action_save_;

	// operator tool
	QAction							*action_loadmesh_;
	QAction							*action_loadtexture_;
	QAction							*action_background_;

	// subdivision operator
	QAction                         *action_subdivide_;

	// render radioButtons
	QCheckBox						*checkbox_point_;
	QCheckBox						*checkbox_edge_;
	QCheckBox						*checkbox_face_;
	QCheckBox						*checkbox_light_;
	QCheckBox						*checkbox_texture_;
	QCheckBox						*checkbox_axes_;

	// Subdivide methods
	QRadioButton                    *radiobutton_loop_;
	QRadioButton                    *radiobutton_catmullclark_;
	QRadioButton                    *radiobutton_doosabin_;
	QRadioButton                    *radiobutton_quadtri_;
	
	// information
	QLabel							*label_meshinfo_;
	QLabel							*label_operatorinfo_;

	RenderingWidget					*renderingwidget_;
};

#endif // MAINWINDOW_H
