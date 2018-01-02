#include "mainwindow.h"

#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QLayout>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QRadioButton>
#include <QtWidgets/QMessageBox>
#include <QKeyEvent>
#include "renderingwidget.h"

MainWindow::MainWindow(QWidget *parent)
	: QMainWindow(parent)
{
	ui.setupUi(this);

	renderingwidget_ = new RenderingWidget(this);
//	setCentralWidget(renderingwidget_);

	setGeometry(300, 150, 800, 600);

	CreateActions();
	CreateMenus();
	CreateToolBars();
	CreateStatusBars();
	CreateGroupBoxes();

	slider_ = new QSlider(Qt::Horizontal,this);
	slider_->setMinimum(0);
	slider_->setMaximum(100);
	slider_->setValue(50);
	connect(slider_, SIGNAL(valueChanged(int)), renderingwidget_, SLOT(SetStiffness(int)));


	QVBoxLayout *layout_left = new QVBoxLayout;
	layout_left->addWidget(groupbox_render_);
	layout_left->addWidget(groupbox_subdivide_);
	layout_left->addWidget(slider_);
	layout_left->addStretch(3);

	QHBoxLayout *layout_main = new QHBoxLayout;

	layout_main->addLayout(layout_left);
	layout_main->addWidget(renderingwidget_);
	layout_main->setStretch(1, 1);
	this->centralWidget()->setLayout(layout_main);
}

MainWindow::~MainWindow()
{

}

void MainWindow::CreateActions()
{
	action_new_ = new QAction(QIcon(":/Resources/images/new.png"), tr("&New"), this);
	action_new_->setShortcut(QKeySequence::New);
	action_new_->setStatusTip(tr("Create a new file"));

	action_open_ = new QAction(QIcon(":/Resources/images/open.png"), tr("&Open..."), this);
	action_open_->setShortcuts(QKeySequence::Open);
	action_open_->setStatusTip(tr("Open an existing file"));
	connect(action_open_, SIGNAL(triggered()), renderingwidget_, SLOT(ReadMesh()));

	action_save_ = new QAction(QIcon(":/Resources/images/save.png"), tr("&Save"), this);
	action_save_->setShortcuts(QKeySequence::Save);
	action_save_->setStatusTip(tr("Save the document to disk"));
	connect(action_save_, SIGNAL(triggered()), renderingwidget_, SLOT(WriteMesh()));

	action_loadmesh_ = new QAction(tr("readOBJ"), this);
	action_loadtexture_ = new QAction(tr("LoadTexture"), this);
	action_background_ = new QAction(tr("ChangeBackground"), this);

	connect(action_loadmesh_, SIGNAL(triggered()), renderingwidget_, SLOT(ReadMesh()));
	connect(action_loadtexture_, SIGNAL(triggered()), renderingwidget_, SLOT(LoadTexture()));
	connect(action_background_, SIGNAL(triggered()), renderingwidget_, SLOT(SetBackground()));

	action_subdivide_ = new QAction(tr("Subdivide"), this);
	action_subdivide_->setStatusTip(tr("Select a subdivision algorithm"));
	connect(action_subdivide_, SIGNAL(triggered()), renderingwidget_, SLOT(Subdivide()));
}

void MainWindow::CreateMenus()
{
	menu_file_ = menuBar()->addMenu(tr("&File"));
	menu_file_->setStatusTip(tr("File menu"));
	menu_file_->addAction(action_new_);
	menu_file_->addAction(action_open_);
	menu_file_->addAction(action_save_);

	menu_edit_ = menuBar()->addMenu(tr("&Edit"));
	menu_edit_->setStatusTip(tr("Edit menu"));
	menu_edit_->addAction(action_subdivide_);
}

void MainWindow::CreateToolBars()
{
	toolbar_file_ = addToolBar(tr("File"));
	toolbar_file_->addAction(action_new_);
	toolbar_file_->addAction(action_open_);
	toolbar_file_->addAction(action_save_);

	toolbar_basic_ = addToolBar(tr("Basic"));
	toolbar_basic_->addAction(action_loadmesh_);
	toolbar_basic_->addAction(action_loadtexture_);
	toolbar_basic_->addAction(action_background_);

	toolbar_edit_ = addToolBar(tr("Edit"));
	toolbar_edit_->addAction(action_subdivide_);
}
 
void MainWindow::CreateStatusBars()
{
	label_meshinfo_ = new QLabel(QString("MeshInfo: p: %1 e: %2 f: %3").arg(0).arg(0).arg(0));
	label_meshinfo_->setAlignment(Qt::AlignCenter);
	label_meshinfo_->setMinimumSize(label_meshinfo_->sizeHint());

	label_operatorinfo_ = new QLabel();
	label_operatorinfo_->setAlignment(Qt::AlignVCenter);
	

	statusBar()->addWidget(label_meshinfo_);
	connect(renderingwidget_, SIGNAL(meshInfo(int, int, int)), this, SLOT(ShowMeshInfo(int, int, int)));

	statusBar()->addWidget(label_operatorinfo_);
	connect(renderingwidget_, SIGNAL(operatorInfo(QString)), label_operatorinfo_, SLOT(setText(QString)));
}

void MainWindow::CreateGroupBoxes()
{
	checkbox_point_ = new QCheckBox(tr("Point"), this);
	connect(checkbox_point_, SIGNAL(clicked(bool)), renderingwidget_, SLOT(CheckDrawPoint(bool)));
	checkbox_point_->setChecked(true);

	checkbox_edge_ = new QCheckBox(tr("Edge"), this);
	connect(checkbox_edge_, SIGNAL(clicked(bool)), renderingwidget_, SLOT(CheckDrawEdge(bool)));
	checkbox_point_->setChecked(true);

	checkbox_face_ = new QCheckBox(tr("Face"), this);
	connect(checkbox_face_, SIGNAL(clicked(bool)), renderingwidget_, SLOT(CheckDrawFace(bool)));
	
	checkbox_light_ = new QCheckBox(tr("Light"), this);
	connect(checkbox_light_, SIGNAL(clicked(bool)), renderingwidget_, SLOT(CheckLight(bool)));

	checkbox_texture_ = new QCheckBox(tr("Texture"), this);
	connect(checkbox_texture_, SIGNAL(clicked(bool)), renderingwidget_, SLOT(CheckDrawTexture(bool)));

	checkbox_axes_ = new QCheckBox(tr("Axes"), this);
	connect(checkbox_axes_, SIGNAL(clicked(bool)), renderingwidget_, SLOT(CheckDrawAxes(bool)));

	groupbox_render_ = new QGroupBox(tr("Render"), this);

	QVBoxLayout* render_layout = new QVBoxLayout(groupbox_render_);
	render_layout->addWidget(checkbox_point_);
	render_layout->addWidget(checkbox_edge_);
	render_layout->addWidget(checkbox_face_);
	render_layout->addWidget(checkbox_texture_);
	render_layout->addWidget(checkbox_light_);
	render_layout->addWidget(checkbox_axes_);

	radiobutton_loop_ = new QRadioButton(tr("Loop"), this);
	connect(radiobutton_loop_, SIGNAL(clicked(bool)), renderingwidget_, SLOT(CheckLoop(bool)));

	radiobutton_catmullclark_ = new QRadioButton(tr("CatmullClark"), this);
	connect(radiobutton_catmullclark_, SIGNAL(clicked(bool)), renderingwidget_, SLOT(CheckCC(bool)));

	radiobutton_doosabin_ = new QRadioButton(tr("DooSabin"), this);
	connect(radiobutton_doosabin_, SIGNAL(clicked(bool)), renderingwidget_, SLOT(CheckDS(bool)));

	radiobutton_quadtri_ = new QRadioButton(tr("QuadTri"), this);
	connect(radiobutton_quadtri_, SIGNAL(clicked(bool)), renderingwidget_, SLOT(CheckQT(bool)));

	groupbox_subdivide_ = new QGroupBox(tr("Method"),this);

	QVBoxLayout* para_layout = new QVBoxLayout(groupbox_subdivide_);
	para_layout->addWidget(radiobutton_loop_);
	para_layout->addWidget(radiobutton_catmullclark_);
	para_layout->addWidget(radiobutton_doosabin_);
	para_layout->addWidget(radiobutton_quadtri_);
}

void MainWindow::keyPressEvent(QKeyEvent *e)
{
}

void MainWindow::keyReleaseEvent(QKeyEvent *e)
{
}

void MainWindow::ShowMeshInfo(int npoint, int nedge, int nface)
{
	label_meshinfo_->setText(QString("MeshInfo: p: %1 e: %2 f: %3").arg(npoint).arg(nedge).arg(nface));
}

void MainWindow::OpenFile()
{
}

void MainWindow::ShowAbout()
{
	QMessageBox::information(this, "About QtMeshFrame-1.0.1",

		QString("<h3>This MeshFrame provides some operations about *.obj files sunch as") +
		" IO, render with points , edges, triangles or textures and some interactions with mouse."
		" A fix light source is provided for you."
		"This is a basic and raw frame for handling meshes. The mesh is of half_edge struct.\n"
		"Please contact" "<font color=blue> wkcagd@mail.ustc.edu.cn<\font><font color=black>, Kang Wang if you has any questions.<\font><\h3>"
		,
		QMessageBox::Ok);
}