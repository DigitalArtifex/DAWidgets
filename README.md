# DigitalArtifexWidgets
A collection of animated Qt widgets, packaged as a QtCreator plugin
![alt text](https://github.com/DigitalArtifex/DigitalArtifexWidgets/blob/main/images/complete.png)

## Installation (Linux)
1) Download the appropriate QtSDK version for your version of QtCreator. This can be found in "Help -> About Qt Creator". The plugin will not work if the versions do not match.
2) Build the project on the target machine with QtCreator or qmake, making sure to use the "Profile" target so both Release and Debug get compiled.
3) Open a terminal and navigate to the appropriate build directory
4) Run `sudo ./install.sh`. If `--path=` is not supplied or blank, then it is assumed that Qt's installation path is `/opt/Qt`

## Installation (Windows)
While this plugin will also work on Windows, the installation script is not currently provided. Follow the first 2 steps from the Linux instructions then manually copy the headers to the `QTINSTALLPATH/VERSION/ARCH/include/DigitalArtifex` directory, then the libraries to both `QTINSTALLPATH/VERSION/ARCH/lib` and `QTINSTALLPATH/Tools/QtCreator/lib/Qt/plugins/designer/`. If you want it to work with the stand-alone designer, the libraries will also need to be copied to `QTINSTALLPATH/VERSION/ARCH/plugins/designer`

## Usage
This plugin has not yet been setup as a QtModule, so you will need to manually link the library by adding the following line to your `.pro` file. This means you will also have to remain on the version you compiled the plugin for, or copy the libraries to a common lib directory

``` C++
LIBS += -L$$[QT_HOST_LIBS] -ldigitalartifexwidgets
```

### QGaugeWidget

QGaugeWidget supports the display format for temperature, percentage and raw values by passing either `QGaugeWidget::Temperature`, `QGaugeWidget::Percent` or `QGaugeWidget::Value` to the constructor as the Mode flag.

<table>
<tr>
<th> Temperature </th>
<th> Percentage </th>
<th> Raw Value </th>
</tr>
<tr>
<td>
<img src="https://github.com/DigitalArtifex/QGaugeWidget/blob/main/images/screenshot.png" />
</td>
<td>
<img src="https://github.com/DigitalArtifex/QGaugeWidget/blob/main/images/percent.png" />
</td>
<td>
<img src="https://github.com/DigitalArtifex/QGaugeWidget/blob/main/images/value.png" />
</td>
</tr>
</table>

``` C++
    m_temperatureGauge = new QGaugeWidget(this, QGaugeWidget::Temperature);
    m_temperatureGauge->setFixedSize(150,150);
    m_temperatureGauge->setIconSize(QSize(36,36));
    m_temperatureGauge->setIcon(QIcon(":/icons/temperature.png"));
    m_temperatureGauge->setMaximum(100);
    m_temperatureLayout->addWidget(m_temperatureGauge);
```

#### Icons

Icons can either be a QIcon object or an animated GIF. If you prefer to use an animated GIF as an icon use `QGaugeWidget::setAnimatedIcon` with the URI of the GIF

``` C++
    m_temperatureGauge->setAnimatedIcon(":/icons/temperature.gif");
```

#### Customization

Typical customization for font, text color, background color, icon size etc are available through their respective setter functions and can be customized via QSS.

You can also set the pen style of the bar and fill if you want dashed lines etc

![alt text](https://github.com/DigitalArtifex/QGaugeWidget/blob/main/images/pen-style.png)

``` C++
    m_temperatureGaugePen.setCapStyle(Qt::FlatCap);
    m_temperatureGaugePen.setColor(m_temperatureGaugeColor);
    m_temperatureGaugePen.setWidth(m_pathWidth + 4);
    m_temperatureGauge->setProgressBarPen(m_temperatureGaugePen);

    m_temperatureGaugeFillPen.setWidth(m_pathWidth);
    m_temperatureGaugeFillPen.setColor(m_temperatureGaugeFillColor);
    m_temperatureGaugeFillPen.setCapStyle(Qt::FlatCap);
    m_temperatureGaugeFillPen.setStyle(Qt::DashDotDotLine);
    m_temperatureGauge->setProgressBarFillPen(m_temperatureGaugeFillPen);
```

### QIndicatorWidget
Customizable status indicator widget

![alt text](https://github.com/DigitalArtifex/DigitalArtifexWidgets/blob/main/images/qindicatorwidget.png)

### Usage example
``` C++
    ui->indicatorWidget->setIndicatorBackgroundColor(QColor(0,0,0));
    ui->indicatorWidget->setIndicatorColor(QColor(48,183,224));
    ui->indicatorWidget->setState(QIndicatorWidget::State::Blinking);
```
### QMaskedButton
A button widget that converts images with an alpha channel into a boundary masked button.

![alt text](https://github.com/DigitalArtifex/DigitalArtifexWidgets/blob/main/images/qmaskedbutton.png)

### Example
Each button requires 3 images. One for the normal state, one for the hover state and one for the clicked state. Disabled state is just the normal state at 50% opacity

``` C++
    ui->xDownButton->setPixmap(xDownImage);
    ui->xDownButton->setClickPixmap(xDownClickedImage);
    ui->xDownButton->setHoverPixmap(xDownHoverImage);
    ui->xDownButton->setFixedSize(317, 218);
    connect(m_xDownButton, SIGNAL(clicked()), this, SLOT(onXDownButtonClicked()));
```

In this example, multiple QMaskedButtons are stacked on the same geometry (0,0,317,218) and each button's image only has image data in their respective locations. The mask for the buttons is generated automatically based on the normal state's pixmap.
<table>
<tr>
<th> X-Up Image </th>
<th> X-Down Image </th>
</tr>
<tr>
<td>
<img src="https://github.com/DigitalArtifex/Flo/blob/main/images/ui/toolhead/x_up_control_image.png" />
</td>
<td>
<img src="https://github.com/DigitalArtifex/Flo/blob/main/images/ui/toolhead/x_down_control_image.png" />
</td>
</tr>
</table>

### QThrobber
Customizable throbber widget for Qt that uses QPainter rather than gifs to provide a clean and undistorted indicator. The throbber rotates, shrinks and grows as a helpful way to indiciate a state of busyness, loading or processing.

![alt text](https://github.com/DigitalArtifex/DigitalArtifexWidgets/blob/main/images/qthrobber.png)

#### Example
``` C++
    QThrobber *throbber = new QThrobber(ui->widget);
    throbber->setFixedSize(150,150);
    throbber->setText("Loading");
    throbber->setSpeed(QThrobber::Normal);
    throbber->setIcon(QIcon(":/icons/icons8-temperature.svg"));
    ui->widget->layout()->addWidget(throbber);

    throbber->start(); //start animation
```

If desired, you can pass a configured QPen object to the `setPen(...)` method. Setting the pen will override the size and color set with `setThrobberWidth(...)` and `setThrobberColor(...)` methods.

This is the preferred way to use color gradiants and dash styles
``` C++
    QPen pen;
    pen.setWidth(4);
    pen.setColor("#F1F44E");
    pen.setCapStyle(Qt::RoundCap);

    throbber->setPen(pen);
```

The icon passed to QThrobber can be set to animate it's scale and/or opacity with the `setIconScaleAnimationEnabled(...)` and `setIconOpacityAnimationEnabled(...)`. By default, only the icon opacity animation is enabled
