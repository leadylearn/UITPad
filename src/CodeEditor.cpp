#include "CodeEditor.h"

#include <QFont>
#include <QFontDatabase>
#include <QWidget>

CodeEditor::CodeEditor(QWidget *parent)
    : QPlainTextEdit(parent)
{
    QFont editorFont = QFontDatabase::systemFont(QFontDatabase::FixedFont);
    editorFont.setPointSize(12);
    setFont(editorFont);
    setPlaceholderText(QStringLiteral("Écrivez votre code ici…"));
    setLineWrapMode(QPlainTextEdit::NoWrap);
}
