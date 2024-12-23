/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.15.8
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDoubleSpinBox>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpinBox>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTabWidget>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralwidget;
    QWidget *gridLayoutWidget;
    QGridLayout *gridLayout;
    QTabWidget *tabWidget;
    QWidget *tabView;
    QWidget *horizontalLayoutWidget_4;
    QHBoxLayout *horizontalLayout_4;
    QDoubleSpinBox *newPosX;
    QDoubleSpinBox *newPosY;
    QDoubleSpinBox *newPosZ;
    QPushButton *buttonMovePos;
    QWidget *horizontalLayoutWidget_2;
    QHBoxLayout *horizontalLayout;
    QDoubleSpinBox *biasX;
    QDoubleSpinBox *biasY;
    QDoubleSpinBox *biasZ;
    QPushButton *buttonMoveBias;
    QWidget *horizontalLayoutWidget;
    QHBoxLayout *horizontalLayoutAng;
    QDoubleSpinBox *angleX;
    QDoubleSpinBox *angleY;
    QDoubleSpinBox *angleZ;
    QPushButton *buttonRotate;
    QPushButton *buttoninitialState;
    QLabel *label;
    QLabel *label_2;
    QLabel *label_3;
    QWidget *tab_2;
    QWidget *horizontalLayoutWidget_3;
    QHBoxLayout *horizontalLayout_2;
    QLabel *label_4;
    QLabel *label_5;
    QWidget *horizontalLayoutWidget_5;
    QHBoxLayout *horizontalLayout_3;
    QLabel *label_6;
    QLabel *label_7;
    QPushButton *gameInitialStateButton;
    QWidget *horizontalLayoutWidget_6;
    QHBoxLayout *horizontalLayout_5;
    QLineEdit *curPosLetter;
    QSpinBox *currPosNumber;
    QWidget *horizontalLayoutWidget_7;
    QHBoxLayout *horizontalLayout_6;
    QLineEdit *nextPosLetter;
    QSpinBox *nextPosNumber;
    QLabel *label_8;
    QLabel *label_9;
    QPushButton *makeMoveButton;
    QWidget *tab_3;
    QWidget *tab_4;
    QWidget *verticalLayoutWidget;
    QVBoxLayout *verticalLayoutView;
    QLabel *labelView;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QString::fromUtf8("MainWindow"));
        MainWindow->resize(1737, 801);
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        gridLayoutWidget = new QWidget(centralwidget);
        gridLayoutWidget->setObjectName(QString::fromUtf8("gridLayoutWidget"));
        gridLayoutWidget->setGeometry(QRect(0, 10, 661, 1071));
        gridLayout = new QGridLayout(gridLayoutWidget);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        gridLayout->setContentsMargins(0, 0, 0, 0);
        tabWidget = new QTabWidget(gridLayoutWidget);
        tabWidget->setObjectName(QString::fromUtf8("tabWidget"));
        tabView = new QWidget();
        tabView->setObjectName(QString::fromUtf8("tabView"));
        horizontalLayoutWidget_4 = new QWidget(tabView);
        horizontalLayoutWidget_4->setObjectName(QString::fromUtf8("horizontalLayoutWidget_4"));
        horizontalLayoutWidget_4->setGeometry(QRect(20, 250, 621, 80));
        horizontalLayout_4 = new QHBoxLayout(horizontalLayoutWidget_4);
        horizontalLayout_4->setObjectName(QString::fromUtf8("horizontalLayout_4"));
        horizontalLayout_4->setContentsMargins(0, 0, 0, 0);
        newPosX = new QDoubleSpinBox(horizontalLayoutWidget_4);
        newPosX->setObjectName(QString::fromUtf8("newPosX"));

        horizontalLayout_4->addWidget(newPosX);

        newPosY = new QDoubleSpinBox(horizontalLayoutWidget_4);
        newPosY->setObjectName(QString::fromUtf8("newPosY"));

        horizontalLayout_4->addWidget(newPosY);

        newPosZ = new QDoubleSpinBox(horizontalLayoutWidget_4);
        newPosZ->setObjectName(QString::fromUtf8("newPosZ"));

        horizontalLayout_4->addWidget(newPosZ);

        buttonMovePos = new QPushButton(horizontalLayoutWidget_4);
        buttonMovePos->setObjectName(QString::fromUtf8("buttonMovePos"));

        horizontalLayout_4->addWidget(buttonMovePos);

        horizontalLayoutWidget_2 = new QWidget(tabView);
        horizontalLayoutWidget_2->setObjectName(QString::fromUtf8("horizontalLayoutWidget_2"));
        horizontalLayoutWidget_2->setGeometry(QRect(20, 420, 621, 80));
        horizontalLayout = new QHBoxLayout(horizontalLayoutWidget_2);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        horizontalLayout->setContentsMargins(0, 0, 0, 0);
        biasX = new QDoubleSpinBox(horizontalLayoutWidget_2);
        biasX->setObjectName(QString::fromUtf8("biasX"));

        horizontalLayout->addWidget(biasX);

        biasY = new QDoubleSpinBox(horizontalLayoutWidget_2);
        biasY->setObjectName(QString::fromUtf8("biasY"));

        horizontalLayout->addWidget(biasY);

        biasZ = new QDoubleSpinBox(horizontalLayoutWidget_2);
        biasZ->setObjectName(QString::fromUtf8("biasZ"));

        horizontalLayout->addWidget(biasZ);

        buttonMoveBias = new QPushButton(horizontalLayoutWidget_2);
        buttonMoveBias->setObjectName(QString::fromUtf8("buttonMoveBias"));

        horizontalLayout->addWidget(buttonMoveBias);

        horizontalLayoutWidget = new QWidget(tabView);
        horizontalLayoutWidget->setObjectName(QString::fromUtf8("horizontalLayoutWidget"));
        horizontalLayoutWidget->setGeometry(QRect(20, 90, 621, 81));
        horizontalLayoutAng = new QHBoxLayout(horizontalLayoutWidget);
        horizontalLayoutAng->setObjectName(QString::fromUtf8("horizontalLayoutAng"));
        horizontalLayoutAng->setContentsMargins(0, 0, 0, 0);
        angleX = new QDoubleSpinBox(horizontalLayoutWidget);
        angleX->setObjectName(QString::fromUtf8("angleX"));
        angleX->setMinimum(-360.000000000000000);
        angleX->setMaximum(360.000000000000000);

        horizontalLayoutAng->addWidget(angleX);

        angleY = new QDoubleSpinBox(horizontalLayoutWidget);
        angleY->setObjectName(QString::fromUtf8("angleY"));
        angleY->setMinimum(-360.000000000000000);
        angleY->setMaximum(360.000000000000000);

        horizontalLayoutAng->addWidget(angleY);

        angleZ = new QDoubleSpinBox(horizontalLayoutWidget);
        angleZ->setObjectName(QString::fromUtf8("angleZ"));
        angleZ->setMinimum(-360.000000000000000);
        angleZ->setMaximum(360.000000000000000);
        angleZ->setValue(0.000000000000000);

        horizontalLayoutAng->addWidget(angleZ);

        buttonRotate = new QPushButton(horizontalLayoutWidget);
        buttonRotate->setObjectName(QString::fromUtf8("buttonRotate"));

        horizontalLayoutAng->addWidget(buttonRotate);

        buttoninitialState = new QPushButton(tabView);
        buttoninitialState->setObjectName(QString::fromUtf8("buttoninitialState"));
        buttoninitialState->setGeometry(QRect(90, 620, 361, 61));
        label = new QLabel(tabView);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(10, 70, 141, 19));
        label_2 = new QLabel(tabView);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setGeometry(QRect(10, 230, 291, 19));
        label_3 = new QLabel(tabView);
        label_3->setObjectName(QString::fromUtf8("label_3"));
        label_3->setGeometry(QRect(10, 400, 291, 19));
        tabWidget->addTab(tabView, QString());
        tab_2 = new QWidget();
        tab_2->setObjectName(QString::fromUtf8("tab_2"));
        tab_2->setEnabled(true);
        horizontalLayoutWidget_3 = new QWidget(tab_2);
        horizontalLayoutWidget_3->setObjectName(QString::fromUtf8("horizontalLayoutWidget_3"));
        horizontalLayoutWidget_3->setGeometry(QRect(40, 20, 371, 80));
        horizontalLayout_2 = new QHBoxLayout(horizontalLayoutWidget_3);
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        horizontalLayout_2->setContentsMargins(0, 0, 0, 0);
        label_4 = new QLabel(horizontalLayoutWidget_3);
        label_4->setObjectName(QString::fromUtf8("label_4"));

        horizontalLayout_2->addWidget(label_4);

        label_5 = new QLabel(horizontalLayoutWidget_3);
        label_5->setObjectName(QString::fromUtf8("label_5"));

        horizontalLayout_2->addWidget(label_5);

        horizontalLayoutWidget_5 = new QWidget(tab_2);
        horizontalLayoutWidget_5->setObjectName(QString::fromUtf8("horizontalLayoutWidget_5"));
        horizontalLayoutWidget_5->setGeometry(QRect(40, 110, 371, 80));
        horizontalLayout_3 = new QHBoxLayout(horizontalLayoutWidget_5);
        horizontalLayout_3->setObjectName(QString::fromUtf8("horizontalLayout_3"));
        horizontalLayout_3->setContentsMargins(0, 0, 0, 0);
        label_6 = new QLabel(horizontalLayoutWidget_5);
        label_6->setObjectName(QString::fromUtf8("label_6"));

        horizontalLayout_3->addWidget(label_6);

        label_7 = new QLabel(horizontalLayoutWidget_5);
        label_7->setObjectName(QString::fromUtf8("label_7"));

        horizontalLayout_3->addWidget(label_7);

        gameInitialStateButton = new QPushButton(tab_2);
        gameInitialStateButton->setObjectName(QString::fromUtf8("gameInitialStateButton"));
        gameInitialStateButton->setGeometry(QRect(90, 600, 281, 71));
        horizontalLayoutWidget_6 = new QWidget(tab_2);
        horizontalLayoutWidget_6->setObjectName(QString::fromUtf8("horizontalLayoutWidget_6"));
        horizontalLayoutWidget_6->setGeometry(QRect(100, 280, 214, 80));
        horizontalLayout_5 = new QHBoxLayout(horizontalLayoutWidget_6);
        horizontalLayout_5->setObjectName(QString::fromUtf8("horizontalLayout_5"));
        horizontalLayout_5->setContentsMargins(0, 0, 0, 0);
        curPosLetter = new QLineEdit(horizontalLayoutWidget_6);
        curPosLetter->setObjectName(QString::fromUtf8("curPosLetter"));
        curPosLetter->setMaxLength(1);

        horizontalLayout_5->addWidget(curPosLetter);

        currPosNumber = new QSpinBox(horizontalLayoutWidget_6);
        currPosNumber->setObjectName(QString::fromUtf8("currPosNumber"));
        currPosNumber->setMinimum(1);
        currPosNumber->setMaximum(8);
        currPosNumber->setValue(1);

        horizontalLayout_5->addWidget(currPosNumber);

        horizontalLayoutWidget_7 = new QWidget(tab_2);
        horizontalLayoutWidget_7->setObjectName(QString::fromUtf8("horizontalLayoutWidget_7"));
        horizontalLayoutWidget_7->setGeometry(QRect(100, 400, 214, 80));
        horizontalLayout_6 = new QHBoxLayout(horizontalLayoutWidget_7);
        horizontalLayout_6->setObjectName(QString::fromUtf8("horizontalLayout_6"));
        horizontalLayout_6->setContentsMargins(0, 0, 0, 0);
        nextPosLetter = new QLineEdit(horizontalLayoutWidget_7);
        nextPosLetter->setObjectName(QString::fromUtf8("nextPosLetter"));
        nextPosLetter->setMaxLength(1);

        horizontalLayout_6->addWidget(nextPosLetter);

        nextPosNumber = new QSpinBox(horizontalLayoutWidget_7);
        nextPosNumber->setObjectName(QString::fromUtf8("nextPosNumber"));
        nextPosNumber->setMinimum(1);
        nextPosNumber->setMaximum(8);

        horizontalLayout_6->addWidget(nextPosNumber);

        label_8 = new QLabel(tab_2);
        label_8->setObjectName(QString::fromUtf8("label_8"));
        label_8->setGeometry(QRect(110, 250, 201, 19));
        label_9 = new QLabel(tab_2);
        label_9->setObjectName(QString::fromUtf8("label_9"));
        label_9->setGeometry(QRect(100, 370, 271, 19));
        makeMoveButton = new QPushButton(tab_2);
        makeMoveButton->setObjectName(QString::fromUtf8("makeMoveButton"));
        makeMoveButton->setGeometry(QRect(150, 510, 111, 71));
        tabWidget->addTab(tab_2, QString());
        tab_3 = new QWidget();
        tab_3->setObjectName(QString::fromUtf8("tab_3"));
        tab_3->setEnabled(true);
        tabWidget->addTab(tab_3, QString());
        tab_4 = new QWidget();
        tab_4->setObjectName(QString::fromUtf8("tab_4"));
        tab_4->setEnabled(true);
        tabWidget->addTab(tab_4, QString());

        gridLayout->addWidget(tabWidget, 0, 0, 1, 1);

        verticalLayoutWidget = new QWidget(centralwidget);
        verticalLayoutWidget->setObjectName(QString::fromUtf8("verticalLayoutWidget"));
        verticalLayoutWidget->setGeometry(QRect(670, 0, 971, 1081));
        verticalLayoutView = new QVBoxLayout(verticalLayoutWidget);
        verticalLayoutView->setObjectName(QString::fromUtf8("verticalLayoutView"));
        verticalLayoutView->setContentsMargins(0, 0, 0, 0);
        labelView = new QLabel(verticalLayoutWidget);
        labelView->setObjectName(QString::fromUtf8("labelView"));

        verticalLayoutView->addWidget(labelView);

        MainWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(MainWindow);
        menubar->setObjectName(QString::fromUtf8("menubar"));
        menubar->setGeometry(QRect(0, 0, 1737, 29));
        MainWindow->setMenuBar(menubar);
        statusbar = new QStatusBar(MainWindow);
        statusbar->setObjectName(QString::fromUtf8("statusbar"));
        MainWindow->setStatusBar(statusbar);

        retranslateUi(MainWindow);

        tabWidget->setCurrentIndex(1);


        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "MainWindow", nullptr));
        buttonMovePos->setText(QCoreApplication::translate("MainWindow", "\320\237\320\276\320\274\320\265\321\201\321\202\320\270\321\202\321\214!", nullptr));
        buttonMoveBias->setText(QCoreApplication::translate("MainWindow", "\320\237\320\265\321\200\320\265\320\274\320\265\321\201\321\202\320\270\321\202\321\214!", nullptr));
        buttonRotate->setText(QCoreApplication::translate("MainWindow", "\320\237\320\276\320\262\320\265\321\200\320\275\321\203\321\202\321\214!", nullptr));
        buttoninitialState->setText(QCoreApplication::translate("MainWindow", "\320\222\320\265\321\200\320\275\321\203\321\202\321\214 \320\262 \320\270\321\201\321\205\320\276\320\264\320\275\320\276\320\265 \320\277\320\276\320\273\320\276\320\266\320\265\320\275\320\270\320\265", nullptr));
        label->setText(QCoreApplication::translate("MainWindow", "\320\237\320\276\320\262\320\265\321\200\320\275\321\203\321\202\321\214 \320\275\320\260 \321\203\320\263\320\276\320\273:", nullptr));
        label_2->setText(QCoreApplication::translate("MainWindow", "\320\237\320\276\320\274\320\265\321\201\321\202\320\270\321\202\321\214 \321\206\320\265\320\275\321\202\321\200 \320\275\320\260 \320\272\320\276\320\276\321\200\320\264\320\270\320\275\320\260\321\202\321\213:", nullptr));
        label_3->setText(QCoreApplication::translate("MainWindow", "\320\237\320\265\321\200\320\265\320\274\320\265\321\201\321\202\320\270\321\202\321\214 \321\206\320\265\320\275\321\202\321\200 \320\275\320\260:", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(tabView), QCoreApplication::translate("MainWindow", "View", nullptr));
        label_4->setText(QCoreApplication::translate("MainWindow", "\320\246\320\262\320\265\321\202 \320\272\320\273\320\265\321\202\320\272\320\270 a1:", nullptr));
        label_5->setText(QCoreApplication::translate("MainWindow", "\320\267\320\265\320\273\321\221\320\275\321\213\320\271", nullptr));
        label_6->setText(QCoreApplication::translate("MainWindow", "\320\246\320\262\320\265\321\202 \320\272\320\273\320\265\321\202\320\272\320\270 h1:", nullptr));
        label_7->setText(QCoreApplication::translate("MainWindow", "\320\272\321\200\320\260\321\201\320\275\321\213\320\271", nullptr));
        gameInitialStateButton->setText(QCoreApplication::translate("MainWindow", "\320\222\320\265\321\200\320\275\321\203\321\202\321\214 \320\262 \320\270\321\201\321\205\320\276\320\264\320\275\320\276\320\265 \321\201\320\276\321\201\321\202\320\276\321\217\320\275\320\270\320\265", nullptr));
        curPosLetter->setText(QString());
        nextPosLetter->setText(QString());
        label_8->setText(QCoreApplication::translate("MainWindow", "\320\242\320\265\320\272\321\203\321\211\320\260\321\217 \320\277\320\276\320\267\320\270\321\206\320\270\320\270 \321\210\320\260\321\210\320\272\320\270:", nullptr));
        label_9->setText(QCoreApplication::translate("MainWindow", " \320\237\320\276\320\267\320\270\321\206\320\270\321\217, \320\275\320\260 \320\272\320\276\321\202\320\276\321\200\321\203\321\216 \320\277\320\265\321\200\320\265\320\274\320\265\321\201\321\202\320\270\321\202\321\214:", nullptr));
        makeMoveButton->setText(QCoreApplication::translate("MainWindow", "\320\241\320\264\320\265\320\273\320\260\321\202\321\214 \321\205\320\276\320\264", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(tab_2), QCoreApplication::translate("MainWindow", "Game", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(tab_3), QString());
        tabWidget->setTabText(tabWidget->indexOf(tab_4), QString());
        labelView->setText(QCoreApplication::translate("MainWindow", "TextLabel", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
