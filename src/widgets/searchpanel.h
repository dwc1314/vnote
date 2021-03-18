#ifndef SEARCHPANEL_H
#define SEARCHPANEL_H

#include <QFrame>

class QComboBox;
class QCheckBox;

namespace vnotex
{
    class TitleBar;

    class SearchPanel : public QFrame
    {
        Q_OBJECT
    public:
        explicit SearchPanel(QWidget *p_parent = nullptr);

    private:
        void setupUI();

        TitleBar *setupTitleBar(const QString &p_title, QWidget *p_parent = nullptr);

        QComboBox *m_keywordComboBox = nullptr;

        QComboBox *m_searchScopeComboBox = nullptr;

        QComboBox *m_searchObjectComboBox = nullptr;

        QComboBox *m_searchTargetComboBox = nullptr;

        QComboBox *m_filePatternComboBox = nullptr;

        QComboBox *m_searchEngineComboBox = nullptr;

        QCheckBox *m_caseSensitiveCheckBox = nullptr;

        QCheckBox *m_wholeWordOnlyCheckBox = nullptr;

        QCheckBox *m_fuzzySearchCheckBox = nullptr;

        QCheckBox *m_regularExpressionCheckBox = nullptr;
    };
}

#endif // SEARCHPANEL_H
