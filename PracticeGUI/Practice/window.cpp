#include "renderarea.h"
#include "window.h"

#include <QtWidgets>

//! [0]
const int IdRole = Qt::UserRole;
//! [0]

//! [1]
Window::Window()
{
    renderArea = new RenderArea;

    shapeLabel = new QLabel(tr("&Shape:"));
    shapeLabel->setBuddy(shapeComboBox);

    penWidthSpinBox = new QSpinBox;
    penWidthSpinBox->setRange(0, 20);
    penWidthSpinBox->setSpecialValueText(tr("0 (cosmetic pen)"));

    penWidthLabel = new QLabel(tr("Pen &Width:"));
    penWidthLabel->setBuddy(penWidthSpinBox);

    penStyleComboBox = new QComboBox;
    penStyleComboBox->addItem(tr("Solid"), static_cast<int>(Qt::SolidLine));
    penStyleComboBox->addItem(tr("Dash"), static_cast<int>(Qt::DashLine));
    penStyleComboBox->addItem(tr("Dot"), static_cast<int>(Qt::DotLine));
    penStyleComboBox->addItem(tr("Dash Dot"), static_cast<int>(Qt::DashDotLine));
    penStyleComboBox->addItem(tr("Dash Dot Dot"), static_cast<int>(Qt::DashDotDotLine));
    penStyleComboBox->addItem(tr("None"), static_cast<int>(Qt::NoPen));

    penStyleLabel = new QLabel(tr("&Pen Style:"));
    penStyleLabel->setBuddy(penStyleComboBox);

    penCapComboBox = new QComboBox;
    penCapComboBox->addItem(tr("Flat"), Qt::FlatCap);
    penCapComboBox->addItem(tr("Square"), Qt::SquareCap);
    penCapComboBox->addItem(tr("Round"), Qt::RoundCap);

    penCapLabel = new QLabel(tr("Pen &Cap:"));
    penCapLabel->setBuddy(penCapComboBox);

    penJoinComboBox = new QComboBox;
    penJoinComboBox->addItem(tr("Miter"), Qt::MiterJoin);
    penJoinComboBox->addItem(tr("Bevel"), Qt::BevelJoin);
    penJoinComboBox->addItem(tr("Round"), Qt::RoundJoin);

    penJoinLabel = new QLabel(tr("Pen &Join:"));
    penJoinLabel->setBuddy(penJoinComboBox);

    brushStyleComboBox = new QComboBox;
    brushStyleComboBox->addItem(tr("Solid"), static_cast<int>(Qt::SolidPattern));
    brushStyleComboBox->addItem(tr("Horizontal"), static_cast<int>(Qt::HorPattern));
    brushStyleComboBox->addItem(tr("Vertical"), static_cast<int>(Qt::VerPattern));
    brushStyleComboBox->addItem(tr("None"), static_cast<int>(Qt::NoBrush));

    brushStyleLabel = new QLabel(tr("&Brush:"));
    brushStyleLabel->setBuddy(brushStyleComboBox);

    otherOptionsLabel = new QLabel(tr("Options:"));

    antialiasingCheckBox = new QCheckBox(tr("&Antialiasing"));

    transformationsCheckBox = new QCheckBox(tr("&Transformations"));

    connect(shapeComboBox, SIGNAL(activated(int)),
            this, SLOT(shapeChanged()));
    connect(penWidthSpinBox, SIGNAL(valueChanged(int)),
            this, SLOT(penChanged()));
    connect(penStyleComboBox, SIGNAL(activated(int)),
            this, SLOT(penChanged()));
    connect(penCapComboBox, SIGNAL(activated(int)),
            this, SLOT(penChanged()));
    connect(penJoinComboBox, SIGNAL(activated(int)),
            this, SLOT(penChanged()));
    connect(brushStyleComboBox, SIGNAL(activated(int)),
            this, SLOT(brushChanged()));
    connect(antialiasingCheckBox, SIGNAL(toggled(bool)),
            renderArea, SLOT(setAntialiased(bool)));
    connect(transformationsCheckBox, SIGNAL(toggled(bool)),
            renderArea, SLOT(setTransformed(bool)));

    QGridLayout *mainLayout = new QGridLayout;

    mainLayout->setColumnStretch(0, 1);
    mainLayout->setColumnStretch(3, 1);
    mainLayout->addWidget(renderArea, 0, 0, 1, 4);
    mainLayout->addWidget(shapeLabel, 2, 0, Qt::AlignRight);
    mainLayout->addWidget(shapeComboBox, 2, 1);
    mainLayout->addWidget(penWidthLabel, 3, 0, Qt::AlignRight);
    mainLayout->addWidget(penWidthSpinBox, 3, 1);
    mainLayout->addWidget(penStyleLabel, 4, 0, Qt::AlignRight);
    mainLayout->addWidget(penStyleComboBox, 4, 1);
    mainLayout->addWidget(penCapLabel, 3, 2, Qt::AlignRight);
    mainLayout->addWidget(penCapComboBox, 3, 3);
    mainLayout->addWidget(penJoinLabel, 2, 2, Qt::AlignRight);
    mainLayout->addWidget(penJoinComboBox, 2, 3);
    mainLayout->addWidget(brushStyleLabel, 4, 2, Qt::AlignRight);
    mainLayout->addWidget(brushStyleComboBox, 4, 3);
    mainLayout->addWidget(otherOptionsLabel, 5, 0, Qt::AlignRight);
    mainLayout->addWidget(antialiasingCheckBox, 5, 1, 1, 1, Qt::AlignRight);
    mainLayout->addWidget(transformationsCheckBox, 5, 2, 1, 2, Qt::AlignRight);
    setLayout(mainLayout);

    shapeChanged();
    penChanged();
    brushChanged();
    antialiasingCheckBox->setChecked(true);

    setWindowTitle(tr("Basic Drawing"));
}

void Window::shapeChanged()
{
    //shapes shape = shapes(shapeComboBox->itemData(shapeComboBox->currentIndex(), IdRole).toInt());
    //renderArea->setShape(shape);
}

void Window::penChanged()
{
    int width = penWidthSpinBox->value();
    Qt::PenStyle style = Qt::PenStyle(penStyleComboBox->itemData(
            penStyleComboBox->currentIndex(), IdRole).toInt());
    Qt::PenCapStyle cap = Qt::PenCapStyle(penCapComboBox->itemData(
            penCapComboBox->currentIndex(), IdRole).toInt());
    Qt::PenJoinStyle join = Qt::PenJoinStyle(penJoinComboBox->itemData(
            penJoinComboBox->currentIndex(), IdRole).toInt());

    renderArea->setPen(QPen(Qt::blue, width, style, cap, join));
}

void Window::brushChanged()
{
    Qt::BrushStyle style = Qt::BrushStyle(brushStyleComboBox->itemData(brushStyleComboBox->currentIndex(), IdRole).toInt());

    if (style == Qt::LinearGradientPattern) {
        QLinearGradient linearGradient(0, 0, 100, 100);
        linearGradient.setColorAt(0.0, Qt::white);
        linearGradient.setColorAt(0.2, Qt::green);
        linearGradient.setColorAt(1.0, Qt::black);
        renderArea->setBrush(linearGradient);

    } else if (style == Qt::RadialGradientPattern) {
        QRadialGradient radialGradient(50, 50, 50, 70, 70);
        radialGradient.setColorAt(0.0, Qt::white);
        radialGradient.setColorAt(0.2, Qt::green);
        radialGradient.setColorAt(1.0, Qt::black);
        renderArea->setBrush(radialGradient);
    } else if (style == Qt::ConicalGradientPattern) {
        QConicalGradient conicalGradient(50, 50, 150);
        conicalGradient.setColorAt(0.0, Qt::white);
        conicalGradient.setColorAt(0.2, Qt::green);
        conicalGradient.setColorAt(1.0, Qt::black);
        renderArea->setBrush(conicalGradient);

    } else if (style == Qt::TexturePattern) {
        renderArea->setBrush(QBrush(QPixmap(":/images/brick.png")));

    } else {
        renderArea->setBrush(QBrush(Qt::green, style));
    }
}
