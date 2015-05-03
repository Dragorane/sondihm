/********************************************************************************
** Form generated from reading UI file 'accueil.ui'
**
** Created by: Qt User Interface Compiler version 5.2.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_ACCUEIL_H
#define UI_ACCUEIL_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenu>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QTextBrowser>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_accueil
{
public:
    QAction *actionAccueil;
    QAction *actionD_connexion;
    QAction *actionAccueil_2;
    QAction *actionFormulaire;
    QAction *actionD_connexion_2;
    QWidget *centralwidget;
    QWidget *verticalLayoutWidget;
    QVBoxLayout *verticalLayout;
    QLabel *label;
    QSpacerItem *verticalSpacer_2;
    QTextBrowser *textBrowser;
    QSpacerItem *verticalSpacer;
    QLabel *label_2;
    QMenuBar *menuBar;
    QMenu *menuMenu;

    void setupUi(QMainWindow *accueil)
    {
        if (accueil->objectName().isEmpty())
            accueil->setObjectName(QStringLiteral("accueil"));
        accueil->resize(510, 294);
        actionAccueil = new QAction(accueil);
        actionAccueil->setObjectName(QStringLiteral("actionAccueil"));
        actionD_connexion = new QAction(accueil);
        actionD_connexion->setObjectName(QStringLiteral("actionD_connexion"));
        actionAccueil_2 = new QAction(accueil);
        actionAccueil_2->setObjectName(QStringLiteral("actionAccueil_2"));
        actionAccueil_2->setEnabled(false);
        actionFormulaire = new QAction(accueil);
        actionFormulaire->setObjectName(QStringLiteral("actionFormulaire"));
        actionD_connexion_2 = new QAction(accueil);
        actionD_connexion_2->setObjectName(QStringLiteral("actionD_connexion_2"));
        centralwidget = new QWidget(accueil);
        centralwidget->setObjectName(QStringLiteral("centralwidget"));
        verticalLayoutWidget = new QWidget(centralwidget);
        verticalLayoutWidget->setObjectName(QStringLiteral("verticalLayoutWidget"));
        verticalLayoutWidget->setGeometry(QRect(20, 30, 481, 231));
        verticalLayout = new QVBoxLayout(verticalLayoutWidget);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        label = new QLabel(verticalLayoutWidget);
        label->setObjectName(QStringLiteral("label"));
        QFont font;
        font.setPointSize(11);
        font.setBold(true);
        font.setItalic(true);
        font.setWeight(75);
        label->setFont(font);
        label->setAlignment(Qt::AlignCenter);

        verticalLayout->addWidget(label);

        verticalSpacer_2 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout->addItem(verticalSpacer_2);

        textBrowser = new QTextBrowser(verticalLayoutWidget);
        textBrowser->setObjectName(QStringLiteral("textBrowser"));

        verticalLayout->addWidget(textBrowser);

        verticalSpacer = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout->addItem(verticalSpacer);

        label_2 = new QLabel(verticalLayoutWidget);
        label_2->setObjectName(QStringLiteral("label_2"));
        label_2->setFont(font);
        label_2->setAlignment(Qt::AlignCenter);

        verticalLayout->addWidget(label_2);

        accueil->setCentralWidget(centralwidget);
        menuBar = new QMenuBar(accueil);
        menuBar->setObjectName(QStringLiteral("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 510, 20));
        menuMenu = new QMenu(menuBar);
        menuMenu->setObjectName(QStringLiteral("menuMenu"));
        accueil->setMenuBar(menuBar);

        menuBar->addAction(menuMenu->menuAction());
        menuMenu->addAction(actionAccueil_2);
        menuMenu->addAction(actionFormulaire);
        menuMenu->addSeparator();
        menuMenu->addAction(actionD_connexion_2);

        retranslateUi(accueil);
        QObject::connect(actionD_connexion_2, SIGNAL(triggered()), accueil, SLOT(close()));
        QObject::connect(actionFormulaire, SIGNAL(triggered()), accueil, SLOT(on_Formulaire_clicked()));

        QMetaObject::connectSlotsByName(accueil);
    } // setupUi

    void retranslateUi(QMainWindow *accueil)
    {
        accueil->setWindowTitle(QApplication::translate("accueil", "MainWindow", 0));
        actionAccueil->setText(QApplication::translate("accueil", "Accueil", 0));
        actionD_connexion->setText(QApplication::translate("accueil", "D\303\251connexion", 0));
        actionAccueil_2->setText(QApplication::translate("accueil", "Accueil", 0));
        actionFormulaire->setText(QApplication::translate("accueil", "Formulaire", 0));
        actionD_connexion_2->setText(QApplication::translate("accueil", "D\303\251connexion", 0));
        label->setText(QApplication::translate("accueil", "Merci de vous \303\252tre connect\303\251 \303\240 l'application !", 0));
        textBrowser->setHtml(QApplication::translate("accueil", "<!DOCTYPE HTML PUBLIC \"-//W3C//DTD HTML 4.0//EN\" \"http://www.w3.org/TR/REC-html40/strict.dtd\">\n"
"<html><head><meta name=\"qrichtext\" content=\"1\" /><style type=\"text/css\">\n"
"p, li { white-space: pre-wrap; }\n"
"</style></head><body style=\" font-family:'DejaVu Sans'; font-size:9pt; font-weight:400; font-style:normal;\">\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\">A travers le menu ci-dessus vous pouvez :</p>\n"
"<ul style=\"margin-top: 0px; margin-bottom: 0px; margin-left: 0px; margin-right: 0px; -qt-list-indent: 1;\"><li style=\" margin-top:12px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\">Accueil : Retourner \303\240 cette page</li>\n"
"<li style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\">Formulaire : Cr\303\251er des formulaires, y r\303\251pondre et voir les statistiques</li>\n"
"<li style=\" margin"
                        "-top:0px; margin-bottom:12px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\">D\303\251connexion : vous d\303\251connecter</li></ul></body></html>", 0));
        label_2->setText(QApplication::translate("accueil", "Bonne visite !", 0));
        menuMenu->setTitle(QApplication::translate("accueil", "Menu", 0));
    } // retranslateUi

};

namespace Ui {
    class accueil: public Ui_accueil {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_ACCUEIL_H
