/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created: Fri Jun 15 15:57:25 2012
**      by: Qt User Interface Compiler version 4.8.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QGridLayout>
#include <QtGui/QHBoxLayout>
#include <QtGui/QHeaderView>
#include <QtGui/QLabel>
#include <QtGui/QLineEdit>
#include <QtGui/QMainWindow>
#include <QtGui/QMenu>
#include <QtGui/QMenuBar>
#include <QtGui/QPushButton>
#include <QtGui/QSpacerItem>
#include <QtGui/QStatusBar>
#include <QtGui/QTextEdit>
#include <QtGui/QToolBar>
#include <QtGui/QVBoxLayout>
#include <QtGui/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QAction *actionQuit;
    QAction *actionAbout;
    QAction *actionRetablir;
    QAction *actionAnnuler;
    QAction *actionMode_Complexe;
    QAction *actionClavier;
    QAction *actionEntier;
    QAction *actionReel;
    QAction *actionRationnel;
    QAction *actionDegres;
    QAction *actionRadians;
    QAction *action2;
    QAction *action1;
    QWidget *centralWidget;
    QWidget *horizontalLayoutWidget;
    QHBoxLayout *horizontalLayout;
    QVBoxLayout *clavierLayout;
    QGridLayout *gridLayout_2;
    QPushButton *un;
    QPushButton *trois;
    QPushButton *deux;
    QPushButton *quatre;
    QPushButton *sept;
    QPushButton *cinq;
    QPushButton *huit;
    QPushButton *neuf;
    QPushButton *six;
    QPushButton *cmplx;
    QPushButton *expr;
    QPushButton *coma;
    QPushButton *del;
    QPushButton *zero;
    QPushButton *entrer;
    QPushButton *xEgal;
    QPushButton *x;
    QSpacerItem *espace1;
    QLabel *opBinaires;
    QGridLayout *gridLayout;
    QPushButton *div;
    QPushButton *plus;
    QPushButton *moins;
    QPushButton *multi;
    QPushButton *pow;
    QPushButton *mod;
    QSpacerItem *espace2;
    QLabel *opUnaires;
    QGridLayout *gridLayout_3;
    QPushButton *cosh;
    QPushButton *sqrt;
    QPushButton *sin;
    QPushButton *sqr;
    QPushButton *tanh;
    QPushButton *log;
    QPushButton *sinh;
    QPushButton *inv;
    QPushButton *ln;
    QPushButton *tan;
    QPushButton *cos;
    QPushButton *cube;
    QPushButton *fact;
    QPushButton *sign;
    QPushButton *eval;
    QSpacerItem *espace3;
    QLabel *opPile;
    QGridLayout *gridLayout_4;
    QPushButton *dup;
    QPushButton *sum;
    QPushButton *swap;
    QPushButton *mean;
    QPushButton *clear;
    QPushButton *drop;
    QSpacerItem *horizontalSpacer;
    QVBoxLayout *ecrans;
    QLineEdit *champEcr;
    QSpacerItem *verticalSpacer;
    QTextEdit *champAff;
    QSpacerItem *verticalSpacer_2;
    QHBoxLayout *horizontalLayout_3;
    QLabel *label_2;
    QLineEdit *champNbAff;
    QLineEdit *champErr;
    QMenuBar *menuBar;
    QMenu *menuMenu;
    QMenu *menuParam;
    QMenu *menuType_de_Constante;
    QMenu *menuAngle;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QString::fromUtf8("MainWindow"));
        MainWindow->resize(597, 770);
        actionQuit = new QAction(MainWindow);
        actionQuit->setObjectName(QString::fromUtf8("actionQuit"));
        actionAbout = new QAction(MainWindow);
        actionAbout->setObjectName(QString::fromUtf8("actionAbout"));
        actionRetablir = new QAction(MainWindow);
        actionRetablir->setObjectName(QString::fromUtf8("actionRetablir"));
        actionRetablir->setShortcut(QString::fromUtf8("Ctrl+Y"));
        actionAnnuler = new QAction(MainWindow);
        actionAnnuler->setObjectName(QString::fromUtf8("actionAnnuler"));
        actionAnnuler->setShortcut(QString::fromUtf8("Ctrl+Z"));
        actionMode_Complexe = new QAction(MainWindow);
        actionMode_Complexe->setObjectName(QString::fromUtf8("actionMode_Complexe"));
        actionClavier = new QAction(MainWindow);
        actionClavier->setObjectName(QString::fromUtf8("actionClavier"));
        actionEntier = new QAction(MainWindow);
        actionEntier->setObjectName(QString::fromUtf8("actionEntier"));
        actionReel = new QAction(MainWindow);
        actionReel->setObjectName(QString::fromUtf8("actionReel"));
        actionRationnel = new QAction(MainWindow);
        actionRationnel->setObjectName(QString::fromUtf8("actionRationnel"));
        actionDegres = new QAction(MainWindow);
        actionDegres->setObjectName(QString::fromUtf8("actionDegres"));
        actionRadians = new QAction(MainWindow);
        actionRadians->setObjectName(QString::fromUtf8("actionRadians"));
        action2 = new QAction(MainWindow);
        action2->setObjectName(QString::fromUtf8("action2"));
        action1 = new QAction(MainWindow);
        action1->setObjectName(QString::fromUtf8("action1"));
        centralWidget = new QWidget(MainWindow);
        centralWidget->setObjectName(QString::fromUtf8("centralWidget"));
        horizontalLayoutWidget = new QWidget(centralWidget);
        horizontalLayoutWidget->setObjectName(QString::fromUtf8("horizontalLayoutWidget"));
        horizontalLayoutWidget->setGeometry(QRect(16, 13, 562, 678));
        horizontalLayout = new QHBoxLayout(horizontalLayoutWidget);
        horizontalLayout->setSpacing(6);
        horizontalLayout->setContentsMargins(11, 11, 11, 11);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        horizontalLayout->setSizeConstraint(QLayout::SetNoConstraint);
        horizontalLayout->setContentsMargins(0, 0, 0, 0);
        clavierLayout = new QVBoxLayout();
        clavierLayout->setSpacing(6);
        clavierLayout->setObjectName(QString::fromUtf8("clavierLayout"));
        gridLayout_2 = new QGridLayout();
        gridLayout_2->setSpacing(10);
        gridLayout_2->setObjectName(QString::fromUtf8("gridLayout_2"));
        gridLayout_2->setContentsMargins(-1, -1, -1, 0);
        un = new QPushButton(horizontalLayoutWidget);
        un->setObjectName(QString::fromUtf8("un"));

        gridLayout_2->addWidget(un, 3, 0, 1, 1);

        trois = new QPushButton(horizontalLayoutWidget);
        trois->setObjectName(QString::fromUtf8("trois"));

        gridLayout_2->addWidget(trois, 3, 2, 1, 1);

        deux = new QPushButton(horizontalLayoutWidget);
        deux->setObjectName(QString::fromUtf8("deux"));

        gridLayout_2->addWidget(deux, 3, 1, 1, 1);

        quatre = new QPushButton(horizontalLayoutWidget);
        quatre->setObjectName(QString::fromUtf8("quatre"));

        gridLayout_2->addWidget(quatre, 2, 0, 1, 1);

        sept = new QPushButton(horizontalLayoutWidget);
        sept->setObjectName(QString::fromUtf8("sept"));

        gridLayout_2->addWidget(sept, 1, 0, 1, 1);

        cinq = new QPushButton(horizontalLayoutWidget);
        cinq->setObjectName(QString::fromUtf8("cinq"));

        gridLayout_2->addWidget(cinq, 2, 1, 1, 1);

        huit = new QPushButton(horizontalLayoutWidget);
        huit->setObjectName(QString::fromUtf8("huit"));

        gridLayout_2->addWidget(huit, 1, 1, 1, 1);

        neuf = new QPushButton(horizontalLayoutWidget);
        neuf->setObjectName(QString::fromUtf8("neuf"));

        gridLayout_2->addWidget(neuf, 1, 2, 1, 1);

        six = new QPushButton(horizontalLayoutWidget);
        six->setObjectName(QString::fromUtf8("six"));

        gridLayout_2->addWidget(six, 2, 2, 1, 1);

        cmplx = new QPushButton(horizontalLayoutWidget);
        cmplx->setObjectName(QString::fromUtf8("cmplx"));

        gridLayout_2->addWidget(cmplx, 6, 2, 1, 1);

        expr = new QPushButton(horizontalLayoutWidget);
        expr->setObjectName(QString::fromUtf8("expr"));

        gridLayout_2->addWidget(expr, 6, 0, 1, 1);

        coma = new QPushButton(horizontalLayoutWidget);
        coma->setObjectName(QString::fromUtf8("coma"));

        gridLayout_2->addWidget(coma, 6, 1, 1, 1);

        del = new QPushButton(horizontalLayoutWidget);
        del->setObjectName(QString::fromUtf8("del"));

        gridLayout_2->addWidget(del, 4, 0, 1, 1);

        zero = new QPushButton(horizontalLayoutWidget);
        zero->setObjectName(QString::fromUtf8("zero"));

        gridLayout_2->addWidget(zero, 4, 1, 1, 1);

        entrer = new QPushButton(horizontalLayoutWidget);
        entrer->setObjectName(QString::fromUtf8("entrer"));

        gridLayout_2->addWidget(entrer, 4, 2, 1, 1);

        xEgal = new QPushButton(horizontalLayoutWidget);
        xEgal->setObjectName(QString::fromUtf8("xEgal"));

        gridLayout_2->addWidget(xEgal, 7, 0, 1, 1);

        x = new QPushButton(horizontalLayoutWidget);
        x->setObjectName(QString::fromUtf8("x"));

        gridLayout_2->addWidget(x, 7, 1, 1, 1);


        clavierLayout->addLayout(gridLayout_2);

        espace1 = new QSpacerItem(20, 20, QSizePolicy::Minimum, QSizePolicy::Fixed);

        clavierLayout->addItem(espace1);

        opBinaires = new QLabel(horizontalLayoutWidget);
        opBinaires->setObjectName(QString::fromUtf8("opBinaires"));
        QFont font;
        font.setPointSize(12);
        opBinaires->setFont(font);
        opBinaires->setAlignment(Qt::AlignCenter);

        clavierLayout->addWidget(opBinaires);

        gridLayout = new QGridLayout();
        gridLayout->setSpacing(10);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        gridLayout->setContentsMargins(-1, -1, 0, 0);
        div = new QPushButton(horizontalLayoutWidget);
        div->setObjectName(QString::fromUtf8("div"));

        gridLayout->addWidget(div, 2, 0, 1, 1);

        plus = new QPushButton(horizontalLayoutWidget);
        plus->setObjectName(QString::fromUtf8("plus"));

        gridLayout->addWidget(plus, 1, 0, 1, 1);

        moins = new QPushButton(horizontalLayoutWidget);
        moins->setObjectName(QString::fromUtf8("moins"));

        gridLayout->addWidget(moins, 1, 1, 1, 1);

        multi = new QPushButton(horizontalLayoutWidget);
        multi->setObjectName(QString::fromUtf8("multi"));

        gridLayout->addWidget(multi, 1, 2, 1, 1);

        pow = new QPushButton(horizontalLayoutWidget);
        pow->setObjectName(QString::fromUtf8("pow"));

        gridLayout->addWidget(pow, 2, 1, 1, 1);

        mod = new QPushButton(horizontalLayoutWidget);
        mod->setObjectName(QString::fromUtf8("mod"));

        gridLayout->addWidget(mod, 2, 2, 1, 1);


        clavierLayout->addLayout(gridLayout);

        espace2 = new QSpacerItem(20, 20, QSizePolicy::Minimum, QSizePolicy::Fixed);

        clavierLayout->addItem(espace2);

        opUnaires = new QLabel(horizontalLayoutWidget);
        opUnaires->setObjectName(QString::fromUtf8("opUnaires"));
        opUnaires->setFont(font);
        opUnaires->setAlignment(Qt::AlignCenter);

        clavierLayout->addWidget(opUnaires);

        gridLayout_3 = new QGridLayout();
        gridLayout_3->setSpacing(6);
        gridLayout_3->setObjectName(QString::fromUtf8("gridLayout_3"));
        cosh = new QPushButton(horizontalLayoutWidget);
        cosh->setObjectName(QString::fromUtf8("cosh"));

        gridLayout_3->addWidget(cosh, 1, 1, 1, 1);

        sqrt = new QPushButton(horizontalLayoutWidget);
        sqrt->setObjectName(QString::fromUtf8("sqrt"));

        gridLayout_3->addWidget(sqrt, 3, 0, 1, 1);

        sin = new QPushButton(horizontalLayoutWidget);
        sin->setObjectName(QString::fromUtf8("sin"));

        gridLayout_3->addWidget(sin, 0, 0, 1, 1);

        sqr = new QPushButton(horizontalLayoutWidget);
        sqr->setObjectName(QString::fromUtf8("sqr"));

        gridLayout_3->addWidget(sqr, 3, 1, 1, 1);

        tanh = new QPushButton(horizontalLayoutWidget);
        tanh->setObjectName(QString::fromUtf8("tanh"));

        gridLayout_3->addWidget(tanh, 1, 3, 1, 1);

        log = new QPushButton(horizontalLayoutWidget);
        log->setObjectName(QString::fromUtf8("log"));

        gridLayout_3->addWidget(log, 2, 1, 1, 1);

        sinh = new QPushButton(horizontalLayoutWidget);
        sinh->setObjectName(QString::fromUtf8("sinh"));

        gridLayout_3->addWidget(sinh, 1, 0, 1, 1);

        inv = new QPushButton(horizontalLayoutWidget);
        inv->setObjectName(QString::fromUtf8("inv"));

        gridLayout_3->addWidget(inv, 2, 3, 1, 1);

        ln = new QPushButton(horizontalLayoutWidget);
        ln->setObjectName(QString::fromUtf8("ln"));

        gridLayout_3->addWidget(ln, 2, 0, 1, 1);

        tan = new QPushButton(horizontalLayoutWidget);
        tan->setObjectName(QString::fromUtf8("tan"));

        gridLayout_3->addWidget(tan, 0, 3, 1, 1);

        cos = new QPushButton(horizontalLayoutWidget);
        cos->setObjectName(QString::fromUtf8("cos"));

        gridLayout_3->addWidget(cos, 0, 1, 1, 1);

        cube = new QPushButton(horizontalLayoutWidget);
        cube->setObjectName(QString::fromUtf8("cube"));

        gridLayout_3->addWidget(cube, 3, 3, 1, 1);

        fact = new QPushButton(horizontalLayoutWidget);
        fact->setObjectName(QString::fromUtf8("fact"));

        gridLayout_3->addWidget(fact, 4, 0, 1, 1);

        sign = new QPushButton(horizontalLayoutWidget);
        sign->setObjectName(QString::fromUtf8("sign"));

        gridLayout_3->addWidget(sign, 4, 3, 1, 1);

        eval = new QPushButton(horizontalLayoutWidget);
        eval->setObjectName(QString::fromUtf8("eval"));

        gridLayout_3->addWidget(eval, 4, 1, 1, 1);


        clavierLayout->addLayout(gridLayout_3);

        espace3 = new QSpacerItem(20, 20, QSizePolicy::Minimum, QSizePolicy::Fixed);

        clavierLayout->addItem(espace3);

        opPile = new QLabel(horizontalLayoutWidget);
        opPile->setObjectName(QString::fromUtf8("opPile"));
        opPile->setFont(font);
        opPile->setAlignment(Qt::AlignCenter);

        clavierLayout->addWidget(opPile);

        gridLayout_4 = new QGridLayout();
        gridLayout_4->setSpacing(6);
        gridLayout_4->setObjectName(QString::fromUtf8("gridLayout_4"));
        dup = new QPushButton(horizontalLayoutWidget);
        dup->setObjectName(QString::fromUtf8("dup"));

        gridLayout_4->addWidget(dup, 1, 1, 1, 1);

        sum = new QPushButton(horizontalLayoutWidget);
        sum->setObjectName(QString::fromUtf8("sum"));

        gridLayout_4->addWidget(sum, 0, 1, 1, 1);

        swap = new QPushButton(horizontalLayoutWidget);
        swap->setObjectName(QString::fromUtf8("swap"));

        gridLayout_4->addWidget(swap, 0, 0, 1, 1);

        mean = new QPushButton(horizontalLayoutWidget);
        mean->setObjectName(QString::fromUtf8("mean"));

        gridLayout_4->addWidget(mean, 0, 2, 1, 1);

        clear = new QPushButton(horizontalLayoutWidget);
        clear->setObjectName(QString::fromUtf8("clear"));

        gridLayout_4->addWidget(clear, 1, 0, 1, 1);

        drop = new QPushButton(horizontalLayoutWidget);
        drop->setObjectName(QString::fromUtf8("drop"));

        gridLayout_4->addWidget(drop, 1, 2, 1, 1);


        clavierLayout->addLayout(gridLayout_4);


        horizontalLayout->addLayout(clavierLayout);

        horizontalSpacer = new QSpacerItem(15, 20, QSizePolicy::Maximum, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer);

        ecrans = new QVBoxLayout();
        ecrans->setSpacing(6);
        ecrans->setObjectName(QString::fromUtf8("ecrans"));
        champEcr = new QLineEdit(horizontalLayoutWidget);
        champEcr->setObjectName(QString::fromUtf8("champEcr"));
        champEcr->setReadOnly(false);

        ecrans->addWidget(champEcr);

        verticalSpacer = new QSpacerItem(20, 15, QSizePolicy::Minimum, QSizePolicy::Fixed);

        ecrans->addItem(verticalSpacer);

        champAff = new QTextEdit(horizontalLayoutWidget);
        champAff->setObjectName(QString::fromUtf8("champAff"));
        champAff->setReadOnly(true);

        ecrans->addWidget(champAff);

        verticalSpacer_2 = new QSpacerItem(20, 15, QSizePolicy::Minimum, QSizePolicy::Fixed);

        ecrans->addItem(verticalSpacer_2);

        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setSpacing(6);
        horizontalLayout_3->setObjectName(QString::fromUtf8("horizontalLayout_3"));
        label_2 = new QLabel(horizontalLayoutWidget);
        label_2->setObjectName(QString::fromUtf8("label_2"));

        horizontalLayout_3->addWidget(label_2);

        champNbAff = new QLineEdit(horizontalLayoutWidget);
        champNbAff->setObjectName(QString::fromUtf8("champNbAff"));

        horizontalLayout_3->addWidget(champNbAff);


        ecrans->addLayout(horizontalLayout_3);


        horizontalLayout->addLayout(ecrans);

        champErr = new QLineEdit(centralWidget);
        champErr->setObjectName(QString::fromUtf8("champErr"));
        champErr->setEnabled(true);
        champErr->setGeometry(QRect(20, 700, 561, 22));
        champErr->setReadOnly(true);
        MainWindow->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(MainWindow);
        menuBar->setObjectName(QString::fromUtf8("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 597, 22));
        menuMenu = new QMenu(menuBar);
        menuMenu->setObjectName(QString::fromUtf8("menuMenu"));
        menuParam = new QMenu(menuBar);
        menuParam->setObjectName(QString::fromUtf8("menuParam"));
        menuType_de_Constante = new QMenu(menuParam);
        menuType_de_Constante->setObjectName(QString::fromUtf8("menuType_de_Constante"));
        menuAngle = new QMenu(menuParam);
        menuAngle->setObjectName(QString::fromUtf8("menuAngle"));
        MainWindow->setMenuBar(menuBar);
        mainToolBar = new QToolBar(MainWindow);
        mainToolBar->setObjectName(QString::fromUtf8("mainToolBar"));
        MainWindow->addToolBar(Qt::RightToolBarArea, mainToolBar);
        statusBar = new QStatusBar(MainWindow);
        statusBar->setObjectName(QString::fromUtf8("statusBar"));
        MainWindow->setStatusBar(statusBar);

        menuBar->addAction(menuMenu->menuAction());
        menuBar->addAction(menuParam->menuAction());
        menuMenu->addAction(actionRetablir);
        menuMenu->addAction(actionAnnuler);
        menuMenu->addAction(actionQuit);
        menuParam->addAction(menuType_de_Constante->menuAction());
        menuParam->addAction(menuAngle->menuAction());
        menuParam->addAction(actionMode_Complexe);
        menuParam->addAction(actionClavier);
        menuType_de_Constante->addAction(actionEntier);
        menuType_de_Constante->addAction(actionReel);
        menuType_de_Constante->addAction(actionRationnel);
        menuAngle->addAction(actionDegres);
        menuAngle->addAction(actionRadians);

        retranslateUi(MainWindow);
        QObject::connect(actionQuit, SIGNAL(triggered()), MainWindow, SLOT(close()));

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "Calculatrice \303\240 Notation Polonaise Invers\303\251e", 0, QApplication::UnicodeUTF8));
        actionQuit->setText(QApplication::translate("MainWindow", "Quit", 0, QApplication::UnicodeUTF8));
        actionAbout->setText(QApplication::translate("MainWindow", "About", 0, QApplication::UnicodeUTF8));
        actionRetablir->setText(QApplication::translate("MainWindow", "Retablir", 0, QApplication::UnicodeUTF8));
        actionAnnuler->setText(QApplication::translate("MainWindow", "Annuler", 0, QApplication::UnicodeUTF8));
        actionMode_Complexe->setText(QApplication::translate("MainWindow", "Mode Complexe", 0, QApplication::UnicodeUTF8));
        actionClavier->setText(QApplication::translate("MainWindow", "Clavier", 0, QApplication::UnicodeUTF8));
        actionEntier->setText(QApplication::translate("MainWindow", "Entier", 0, QApplication::UnicodeUTF8));
        actionReel->setText(QApplication::translate("MainWindow", "R\303\251el", 0, QApplication::UnicodeUTF8));
        actionRationnel->setText(QApplication::translate("MainWindow", "Rationnel", 0, QApplication::UnicodeUTF8));
        actionDegres->setText(QApplication::translate("MainWindow", "Degres", 0, QApplication::UnicodeUTF8));
        actionRadians->setText(QApplication::translate("MainWindow", "Radians", 0, QApplication::UnicodeUTF8));
        action2->setText(QApplication::translate("MainWindow", "2", 0, QApplication::UnicodeUTF8));
        action1->setText(QApplication::translate("MainWindow", "1", 0, QApplication::UnicodeUTF8));
        un->setText(QApplication::translate("MainWindow", "1", 0, QApplication::UnicodeUTF8));
        un->setShortcut(QApplication::translate("MainWindow", "1", 0, QApplication::UnicodeUTF8));
        trois->setText(QApplication::translate("MainWindow", "3", 0, QApplication::UnicodeUTF8));
        trois->setShortcut(QApplication::translate("MainWindow", "3", 0, QApplication::UnicodeUTF8));
        deux->setText(QApplication::translate("MainWindow", "2", 0, QApplication::UnicodeUTF8));
        deux->setShortcut(QApplication::translate("MainWindow", "2", 0, QApplication::UnicodeUTF8));
        quatre->setText(QApplication::translate("MainWindow", "4", 0, QApplication::UnicodeUTF8));
        quatre->setShortcut(QApplication::translate("MainWindow", "4", 0, QApplication::UnicodeUTF8));
        sept->setText(QApplication::translate("MainWindow", "7", 0, QApplication::UnicodeUTF8));
        sept->setShortcut(QApplication::translate("MainWindow", "7", 0, QApplication::UnicodeUTF8));
        cinq->setText(QApplication::translate("MainWindow", "5", 0, QApplication::UnicodeUTF8));
        cinq->setShortcut(QApplication::translate("MainWindow", "5", 0, QApplication::UnicodeUTF8));
        huit->setText(QApplication::translate("MainWindow", "8", 0, QApplication::UnicodeUTF8));
        huit->setShortcut(QApplication::translate("MainWindow", "8", 0, QApplication::UnicodeUTF8));
        neuf->setText(QApplication::translate("MainWindow", "9", 0, QApplication::UnicodeUTF8));
        neuf->setShortcut(QApplication::translate("MainWindow", "9", 0, QApplication::UnicodeUTF8));
        six->setText(QApplication::translate("MainWindow", "6", 0, QApplication::UnicodeUTF8));
        six->setShortcut(QApplication::translate("MainWindow", "6", 0, QApplication::UnicodeUTF8));
        cmplx->setText(QApplication::translate("MainWindow", "$", 0, QApplication::UnicodeUTF8));
        cmplx->setShortcut(QApplication::translate("MainWindow", "$", 0, QApplication::UnicodeUTF8));
        expr->setText(QApplication::translate("MainWindow", "'", 0, QApplication::UnicodeUTF8));
        expr->setShortcut(QApplication::translate("MainWindow", "'", 0, QApplication::UnicodeUTF8));
        coma->setText(QApplication::translate("MainWindow", ",", 0, QApplication::UnicodeUTF8));
        coma->setShortcut(QApplication::translate("MainWindow", ",", 0, QApplication::UnicodeUTF8));
        del->setText(QApplication::translate("MainWindow", "Del", 0, QApplication::UnicodeUTF8));
        del->setShortcut(QApplication::translate("MainWindow", "Backspace", 0, QApplication::UnicodeUTF8));
        zero->setText(QApplication::translate("MainWindow", "0", 0, QApplication::UnicodeUTF8));
        zero->setShortcut(QApplication::translate("MainWindow", "0", 0, QApplication::UnicodeUTF8));
        entrer->setText(QApplication::translate("MainWindow", "Entrer", 0, QApplication::UnicodeUTF8));
        entrer->setShortcut(QApplication::translate("MainWindow", "Return", 0, QApplication::UnicodeUTF8));
        xEgal->setText(QApplication::translate("MainWindow", "x=", 0, QApplication::UnicodeUTF8));
        x->setText(QApplication::translate("MainWindow", "x", 0, QApplication::UnicodeUTF8));
        opBinaires->setText(QApplication::translate("MainWindow", "Operateurs Binaires", 0, QApplication::UnicodeUTF8));
        div->setText(QApplication::translate("MainWindow", "/", 0, QApplication::UnicodeUTF8));
        div->setShortcut(QApplication::translate("MainWindow", "/", 0, QApplication::UnicodeUTF8));
        plus->setText(QApplication::translate("MainWindow", "+", 0, QApplication::UnicodeUTF8));
        plus->setShortcut(QApplication::translate("MainWindow", "+", 0, QApplication::UnicodeUTF8));
        moins->setText(QApplication::translate("MainWindow", "-", 0, QApplication::UnicodeUTF8));
        moins->setShortcut(QApplication::translate("MainWindow", "-", 0, QApplication::UnicodeUTF8));
        multi->setText(QApplication::translate("MainWindow", "*", 0, QApplication::UnicodeUTF8));
        multi->setShortcut(QApplication::translate("MainWindow", "*", 0, QApplication::UnicodeUTF8));
        pow->setText(QApplication::translate("MainWindow", "Pow", 0, QApplication::UnicodeUTF8));
        mod->setText(QApplication::translate("MainWindow", "Mod", 0, QApplication::UnicodeUTF8));
        opUnaires->setText(QApplication::translate("MainWindow", "Op\303\251rateurs Unaires", 0, QApplication::UnicodeUTF8));
        cosh->setText(QApplication::translate("MainWindow", "CosH", 0, QApplication::UnicodeUTF8));
        sqrt->setText(QApplication::translate("MainWindow", "Sqrt", 0, QApplication::UnicodeUTF8));
        sin->setText(QApplication::translate("MainWindow", "Sin", 0, QApplication::UnicodeUTF8));
        sqr->setText(QApplication::translate("MainWindow", "Sqr", 0, QApplication::UnicodeUTF8));
        tanh->setText(QApplication::translate("MainWindow", "TanH", 0, QApplication::UnicodeUTF8));
        log->setText(QApplication::translate("MainWindow", "Log", 0, QApplication::UnicodeUTF8));
        sinh->setText(QApplication::translate("MainWindow", "SinH", 0, QApplication::UnicodeUTF8));
        inv->setText(QApplication::translate("MainWindow", "Inv", 0, QApplication::UnicodeUTF8));
        ln->setText(QApplication::translate("MainWindow", "Ln", 0, QApplication::UnicodeUTF8));
        tan->setText(QApplication::translate("MainWindow", "Tan", 0, QApplication::UnicodeUTF8));
        cos->setText(QApplication::translate("MainWindow", "Cos", 0, QApplication::UnicodeUTF8));
        cube->setText(QApplication::translate("MainWindow", "Cube", 0, QApplication::UnicodeUTF8));
        fact->setText(QApplication::translate("MainWindow", "!", 0, QApplication::UnicodeUTF8));
        sign->setText(QApplication::translate("MainWindow", "Sign", 0, QApplication::UnicodeUTF8));
        eval->setText(QApplication::translate("MainWindow", "Eval", 0, QApplication::UnicodeUTF8));
        opPile->setText(QApplication::translate("MainWindow", "Op\303\251rateurs de Pile", 0, QApplication::UnicodeUTF8));
        dup->setText(QApplication::translate("MainWindow", "Dup", 0, QApplication::UnicodeUTF8));
        sum->setText(QApplication::translate("MainWindow", "Sum", 0, QApplication::UnicodeUTF8));
        swap->setText(QApplication::translate("MainWindow", "Swap", 0, QApplication::UnicodeUTF8));
        mean->setText(QApplication::translate("MainWindow", "Mean", 0, QApplication::UnicodeUTF8));
        clear->setText(QApplication::translate("MainWindow", "Clear", 0, QApplication::UnicodeUTF8));
        drop->setText(QApplication::translate("MainWindow", "Drop", 0, QApplication::UnicodeUTF8));
        label_2->setText(QApplication::translate("MainWindow", "Nombre de valeurs affich\303\251es : ", 0, QApplication::UnicodeUTF8));
        menuMenu->setTitle(QApplication::translate("MainWindow", "Menu", 0, QApplication::UnicodeUTF8));
        menuParam->setTitle(QApplication::translate("MainWindow", "Parametres", 0, QApplication::UnicodeUTF8));
        menuType_de_Constante->setTitle(QApplication::translate("MainWindow", "Type de Constante", 0, QApplication::UnicodeUTF8));
        menuAngle->setTitle(QApplication::translate("MainWindow", "Mesure d'angle", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
