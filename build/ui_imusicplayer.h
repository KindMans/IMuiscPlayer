/********************************************************************************
** Form generated from reading UI file 'imusicplayer.ui'
**
** Created by: Qt User Interface Compiler version 5.14.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_IMUSICPLAYER_H
#define UI_IMUSICPLAYER_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSlider>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QTabWidget>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_IMusicPlayer
{
public:
    QGridLayout *gridLayout;
    QVBoxLayout *verticalLayout_2;
    QHBoxLayout *horizontalLayout_3;
    QHBoxLayout *horizontalLayout;
    QPushButton *btn_load;
    QComboBox *combox_play_model;
    QSpacerItem *horizontalSpacer;
    QHBoxLayout *horizontalLayout_2;
    QLabel *label;
    QSlider *slider_volume;
    QTabWidget *tabWidget;
    QWidget *tab_now;
    QWidget *tab_history;
    QVBoxLayout *verticalLayout;
    QSlider *slider_position;
    QHBoxLayout *horizontalLayout_4;
    QPushButton *btn_prev;
    QPushButton *btn_pause;
    QPushButton *btn_next;
    QPushButton *btn_player;

    void setupUi(QWidget *IMusicPlayer)
    {
        if (IMusicPlayer->objectName().isEmpty())
            IMusicPlayer->setObjectName(QString::fromUtf8("IMusicPlayer"));
        IMusicPlayer->resize(464, 377);
        gridLayout = new QGridLayout(IMusicPlayer);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        verticalLayout_2 = new QVBoxLayout();
        verticalLayout_2->setObjectName(QString::fromUtf8("verticalLayout_2"));
        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setObjectName(QString::fromUtf8("horizontalLayout_3"));
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        btn_load = new QPushButton(IMusicPlayer);
        btn_load->setObjectName(QString::fromUtf8("btn_load"));

        horizontalLayout->addWidget(btn_load);

        combox_play_model = new QComboBox(IMusicPlayer);
        combox_play_model->addItem(QString());
        combox_play_model->addItem(QString());
        combox_play_model->addItem(QString());
        combox_play_model->setObjectName(QString::fromUtf8("combox_play_model"));

        horizontalLayout->addWidget(combox_play_model);


        horizontalLayout_3->addLayout(horizontalLayout);

        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_3->addItem(horizontalSpacer);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        label = new QLabel(IMusicPlayer);
        label->setObjectName(QString::fromUtf8("label"));

        horizontalLayout_2->addWidget(label);

        slider_volume = new QSlider(IMusicPlayer);
        slider_volume->setObjectName(QString::fromUtf8("slider_volume"));
        slider_volume->setOrientation(Qt::Vertical);

        horizontalLayout_2->addWidget(slider_volume);


        horizontalLayout_3->addLayout(horizontalLayout_2);


        verticalLayout_2->addLayout(horizontalLayout_3);

        tabWidget = new QTabWidget(IMusicPlayer);
        tabWidget->setObjectName(QString::fromUtf8("tabWidget"));
        tab_now = new QWidget();
        tab_now->setObjectName(QString::fromUtf8("tab_now"));
        tabWidget->addTab(tab_now, QString());
        tab_history = new QWidget();
        tab_history->setObjectName(QString::fromUtf8("tab_history"));
        tabWidget->addTab(tab_history, QString());

        verticalLayout_2->addWidget(tabWidget);

        verticalLayout = new QVBoxLayout();
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        slider_position = new QSlider(IMusicPlayer);
        slider_position->setObjectName(QString::fromUtf8("slider_position"));
        slider_position->setOrientation(Qt::Horizontal);

        verticalLayout->addWidget(slider_position);

        horizontalLayout_4 = new QHBoxLayout();
        horizontalLayout_4->setObjectName(QString::fromUtf8("horizontalLayout_4"));
        btn_prev = new QPushButton(IMusicPlayer);
        btn_prev->setObjectName(QString::fromUtf8("btn_prev"));

        horizontalLayout_4->addWidget(btn_prev);

        btn_pause = new QPushButton(IMusicPlayer);
        btn_pause->setObjectName(QString::fromUtf8("btn_pause"));

        horizontalLayout_4->addWidget(btn_pause);

        btn_next = new QPushButton(IMusicPlayer);
        btn_next->setObjectName(QString::fromUtf8("btn_next"));

        horizontalLayout_4->addWidget(btn_next);

        btn_player = new QPushButton(IMusicPlayer);
        btn_player->setObjectName(QString::fromUtf8("btn_player"));

        horizontalLayout_4->addWidget(btn_player);


        verticalLayout->addLayout(horizontalLayout_4);


        verticalLayout_2->addLayout(verticalLayout);

        verticalLayout_2->setStretch(0, 1);
        verticalLayout_2->setStretch(1, 3);
        verticalLayout_2->setStretch(2, 1);

        gridLayout->addLayout(verticalLayout_2, 0, 0, 1, 1);


        retranslateUi(IMusicPlayer);

        tabWidget->setCurrentIndex(1);


        QMetaObject::connectSlotsByName(IMusicPlayer);
    } // setupUi

    void retranslateUi(QWidget *IMusicPlayer)
    {
        IMusicPlayer->setWindowTitle(QCoreApplication::translate("IMusicPlayer", "IMusicPlayer", nullptr));
        btn_load->setText(QCoreApplication::translate("IMusicPlayer", "\345\212\240\350\275\275\346\234\254\345\234\260\351\237\263\344\271\220", nullptr));
        combox_play_model->setItemText(0, QCoreApplication::translate("IMusicPlayer", "\351\241\272\345\272\217\346\222\255\346\224\276", nullptr));
        combox_play_model->setItemText(1, QCoreApplication::translate("IMusicPlayer", "\351\232\217\346\234\272\346\222\255\346\224\276", nullptr));
        combox_play_model->setItemText(2, QCoreApplication::translate("IMusicPlayer", "\345\215\225\346\233\262\345\276\252\347\216\257", nullptr));

        label->setText(QCoreApplication::translate("IMusicPlayer", "\351\237\263\351\207\217\350\260\203\350\212\202", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(tab_now), QCoreApplication::translate("IMusicPlayer", "\346\234\254\345\234\260\351\237\263\344\271\220", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(tab_history), QCoreApplication::translate("IMusicPlayer", "\346\222\255\346\224\276\345\216\206\345\217\262", nullptr));
        btn_prev->setText(QCoreApplication::translate("IMusicPlayer", "\344\270\212\344\270\200\351\246\226", nullptr));
        btn_pause->setText(QCoreApplication::translate("IMusicPlayer", "\346\232\202\345\201\234", nullptr));
        btn_next->setText(QCoreApplication::translate("IMusicPlayer", "\344\270\213\344\270\200\351\246\226", nullptr));
        btn_player->setText(QCoreApplication::translate("IMusicPlayer", "\346\222\255\346\224\276\345\275\223\345\211\215\351\200\211\344\270\255", nullptr));
    } // retranslateUi

};

namespace Ui {
    class IMusicPlayer: public Ui_IMusicPlayer {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_IMUSICPLAYER_H
