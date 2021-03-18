#include "locationlist.h"

#include <QVBoxLayout>

#include "treewidget.h"
#include "widgetsfactory.h"
#include "titlebar.h"

using namespace vnotex;

LocationList::LocationList(QWidget *p_parent)
    : QFrame(p_parent)
{
    setupUI();
}

void LocationList::setupUI()
{
    auto mainLayout = new QVBoxLayout(this);
    mainLayout->setContentsMargins(0, 0, 0, 0);
    mainLayout->setSpacing(0);

    {
        auto titleBar = setupTitleBar(QString(), this);
        mainLayout->addWidget(titleBar);
    }

    m_tree = new TreeWidget(TreeWidget::Flag::None, this);
    m_tree->setHeaderLabels(QStringList() << tr("File") << tr("Location") << tr("Text") << tr("Notes"));
    TreeWidget::showHorizontalScrollbar(m_tree);
    mainLayout->addWidget(m_tree);

    setFocusProxy(m_tree);
}

NavigationModeWrapper<QTreeWidget, QTreeWidgetItem> *LocationList::getNavigationModeWrapper()
{
    if (!m_navigationWrapper) {
        m_navigationWrapper.reset(new NavigationModeWrapper<QTreeWidget, QTreeWidgetItem>(m_tree));
    }
    return m_navigationWrapper.data();
}

TitleBar *LocationList::setupTitleBar(const QString &p_title, QWidget *p_parent)
{
    auto titleBar = new TitleBar(p_title, true, TitleBar::Action::None, p_parent);
    return titleBar;
}
