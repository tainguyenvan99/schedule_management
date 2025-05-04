#include "FormDialog.h"

FormDialog::FormDialog(QDialog *parent) : QDialog(parent)
{
    setWindowFlags(Qt::Dialog | Qt::FramelessWindowHint);
    // setAttribute(Qt::WA_TranslucentBackground);
    setFixedWidth(330);
    setStyleSheet(
        "QDialog { "
        "  border: 2px solidrgb(196, 133, 17); "
        "  border-radius: 10px; "
        "  background-color: white; "
        "} ");
    layout = new QVBoxLayout(this);
    layout->setSpacing(0);
    layout->setContentsMargins(0, 0, 0, 0);
    containerWidget = new QWidget(this);
    QVBoxLayout *containerLayout = new QVBoxLayout(containerWidget);

    // header
    headerLabel = new QLabel(containerWidget);
    headerLabel->setAlignment(Qt::AlignCenter);
    headerLabel->setStyleSheet("font-weight: bold; font-size: 16px;");

    // content
    contentLayout = new QVBoxLayout(this);
    QWidget *contentWidget = new QWidget(containerWidget);
    contentWidget->setLayout(contentLayout);

    // footer
    QDialogButtonBox *buttonBox = new QDialogButtonBox(QDialogButtonBox::Cancel | QDialogButtonBox::Save, this);
    connect(buttonBox, &QDialogButtonBox::rejected, this, &QDialog::reject);
    connect(buttonBox, &QDialogButtonBox::accepted, this, &QDialog::accept);

    // connect(buttonBox, &QDialogButtonBox::accepted, this, &FormDialog::onAccept);
    containerLayout->addWidget(headerLabel);
    containerLayout->addWidget(contentWidget);
    containerLayout->addWidget(buttonBox);
    layout->addWidget(containerWidget);
}

void FormDialog::setHeaderTitle(const QString &title)
{
    headerLabel->setText(title);
}

void FormDialog::addContentLine(const QString &text)
{
    QHBoxLayout *lineLayout = new QHBoxLayout();
    lineLayout->setSpacing(0);
    lineLayout->setContentsMargins(0, 0, 0, 0);
    QLabel *label = new QLabel(text, this);
    QLineEdit *inputField = new QLineEdit(this);
    lineLayout->addWidget(label, 1);
    lineLayout->addWidget(inputField, 2);
    QWidget *wrapper = new QWidget(this);
    wrapper->setLayout(lineLayout);
    fields.append(qMakePair(label, inputField));
    contentLayout->addWidget(wrapper);
}

QVector<QPair<QString, QString>> FormDialog::getLabelInputPairs() const
{
    QVector<QPair<QString, QString>> results;
    for (const auto &pair : fields)
    {
        if (pair.first && pair.second)
        {
            results.append(qMakePair(pair.first->text(), pair.second->text()));
        }
    }
    return results;
}

// void FormDialog::onAccept()
// {
//     QVector<QPair<QString, QString>> entries = getLabelInputPairs();
//     emit formSubmitted(entries);
//     accept();
// }