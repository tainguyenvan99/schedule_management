#ifndef FORMDIALOG_H
#define FORMDIALOG_H

#include <QBoxLayout>
#include <QLabel>
#include <QDialog>
#include <QLineEdit>
#include <QDialogButtonBox>

class FormDialog : public QDialog
{
    Q_OBJECT

public:
    explicit FormDialog(QDialog *parent = nullptr);

    void setHeaderTitle(const QString &title);
    void addContentLine(const QString &text);
    QVector<QPair<QString, QString>> getLabelInputPairs() const;

// private slots:
//     void onAccept();

// signals:
//     void formSubmitted(const QVector<QPair<QString, QString>> &entries);

private:
    QWidget *containerWidget;
    QVBoxLayout *layout;
    QVBoxLayout *contentLayout;
    QLabel *headerLabel;
    QString bGColor;
    QVector<QPair<QLabel *, QLineEdit *>> fields;
};

#endif
 