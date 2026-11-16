#include "MainWindow.h"

#include "CodeEditor.h"

#include <QLabel>
#include <QStatusBar>
#include <QTextCursor>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent),
      m_editor(new CodeEditor(this)),
      m_statusLabel(new QLabel(this))
{
    setWindowTitle(QStringLiteral("Éditeur C++ — prototype"));
    resize(900, 600);

    setCentralWidget(m_editor);

    m_statusLabel->setText(QStringLiteral("Prêt"));
    statusBar()->addPermanentWidget(m_statusLabel);

    connect(m_editor, &QPlainTextEdit::cursorPositionChanged, this, [this]() {
        const QTextCursor cursor = m_editor->textCursor();
        const int line = cursor.blockNumber() + 1;
        const int column = cursor.positionInBlock() + 1;
        m_statusLabel->setText(
            QStringLiteral("Ligne %1, colonne %2").arg(line).arg(column));
    });
}
