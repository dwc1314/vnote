#include "searchpanel.h"

#include <QVBoxLayout>
#include <QToolButton>
#include <QLabel>
#include <QFormLayout>
#include <QComboBox>
#include <QCheckBox>
#include <QLineEdit>
#include <QCompleter>

#include "widgetsfactory.h"
#include "titlebar.h"
#include "propertydefs.h"

using namespace vnotex;

SearchPanel::SearchPanel(QWidget *p_parent)
    : QFrame(p_parent)
{
    setupUI();
}

void SearchPanel::setupUI()
{
    auto mainLayout = new QVBoxLayout(this);
    mainLayout->setContentsMargins(0, 0, 0, 0);

    {
        auto titleBar = setupTitleBar(QString(), this);
        mainLayout->addWidget(titleBar);
    }

    auto inputsLayout = new QFormLayout();
    mainLayout->addLayout(inputsLayout);

    m_keywordComboBox = WidgetsFactory::createComboBox(this);
    m_keywordComboBox->setEditable(true);
    m_keywordComboBox->setLineEdit(WidgetsFactory::createLineEdit(this));
    m_keywordComboBox->lineEdit()->setPlaceholderText(tr("Use Space, &&, or || as separator"));
    m_keywordComboBox->lineEdit()->setProperty(PropertyDefs::c_embeddedLineEdit, true);
    m_keywordComboBox->completer()->setCaseSensitivity(Qt::CaseSensitive);
    inputsLayout->addRow(tr("Keywords:"), m_keywordComboBox);

    m_searchScopeComboBox = WidgetsFactory::createComboBox(this);
    inputsLayout->addRow(tr("Scope:"), m_searchScopeComboBox);

    m_searchObjectComboBox = WidgetsFactory::createComboBox(this);
    inputsLayout->addRow(tr("Object:"), m_searchObjectComboBox);

    m_searchTargetComboBox = WidgetsFactory::createComboBox(this);
    inputsLayout->addRow(tr("Target:"), m_searchTargetComboBox);

    m_filePatternComboBox = WidgetsFactory::createComboBox(this);
    m_filePatternComboBox->setEditable(true);
    m_filePatternComboBox->setLineEdit(WidgetsFactory::createLineEdit(this));
    m_filePatternComboBox->lineEdit()->setPlaceholderText(tr("Wildcard pattern of files and folders to search"));
    m_filePatternComboBox->lineEdit()->setProperty(PropertyDefs::c_embeddedLineEdit, true);
    m_filePatternComboBox->completer()->setCaseSensitivity(Qt::CaseSensitive);
    inputsLayout->addRow(tr("File pattern:"), m_filePatternComboBox);

    m_searchEngineComboBox = WidgetsFactory::createComboBox(this);
    inputsLayout->addRow(tr("Engine:"), m_searchEngineComboBox);

    m_caseSensitiveCheckBox = WidgetsFactory::createCheckBox(tr("&Case sensitive"), this);
    inputsLayout->addRow(m_caseSensitiveCheckBox);

    m_wholeWordOnlyCheckBox = WidgetsFactory::createCheckBox(tr("&Whole word only"), this);
    inputsLayout->addRow(m_wholeWordOnlyCheckBox);

    m_fuzzySearchCheckBox = WidgetsFactory::createCheckBox(tr("&Fuzzy search"), this);
    inputsLayout->addRow(m_fuzzySearchCheckBox);

    m_regularExpressionCheckBox = WidgetsFactory::createCheckBox(tr("Re&gular expression"), this);
    inputsLayout->addRow(m_regularExpressionCheckBox);

    mainLayout->addStretch();
}

TitleBar *SearchPanel::setupTitleBar(const QString &p_title, QWidget *p_parent)
{
    auto titleBar = new TitleBar(p_title, false, TitleBar::Action::None, p_parent);
    titleBar->setActionButtonsAlwaysShown(true);

    {
        auto btn = titleBar->addActionButton(QStringLiteral("search.svg"), tr("Search"));
        connect(btn, &QToolButton::triggered,
                this, [this](QAction *p_act) {
                });
    }

    return titleBar;
}
