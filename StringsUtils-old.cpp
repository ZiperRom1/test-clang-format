/*
 * StringsUtils.cpp
 *
 *  Créé le : 23/10/2017
 *      Auteur : Romain Macureau
 *
 *    methodes statiques utiles
 */
#include <QJsonArray>
#include <QJsonObject>
#include <QVariant>

#include "utils/StringsUtils.hpp"

namespace frlis::utilities {
    const QRegExp NUMBER_REGEX("^-?\\d+([\\.,]\\d+)?$");
    const QRegExp NUMBER_SQL_REGEX("^(\\[|\\])((\\-?\\d+([\\.]\\d+)*)|\\*)(,((\\-?\\d+([\\.]\\d+)*)|\\*))?(\\[|\\])$");
    const QRegExp DATE_REGEX("^([0-2][0-9]|(3)[0-1])(\\/)(((0)[0-9])|((1)[0-2]))(\\/)\\d{4}$");
    const QString DATE_SQL_FORMAT("dd/mm/yyyy");
    const QString DATE_FORMAT("yyyy-MM-dd");
    const QString DATE_TIME_FORMAT("yyyy-MM-dd hh:mm:ss");
    const QRegExp HOUR_REGEX("^(0[0-9]|1[0-9]|2[0-3])[0-5][0-9]$");
    const QRegExp HOUR_REGEX_WITH_H("^(0[0-9]|1[0-9]|2[0-3])[h:][0-5][0-9]$");
    const QRegExp EMAIL_REGEX("[A-Za-z0-9._%+-]+@[A-Za-z0-9._%+-]+\\.[A-Za-z0-9]+");
    const QRegExp ALPHANUMERIC_ASTERISC_REGEX("[A-Za-z0-9 _\\*]+");
    const QRegExp ALPHANUMERIC_REGEX("^[a-zA-Z0-9\\s]+$");
    const QRegExp NUM_SSV_REGEX("[AaBb0-9\\*]+");
    const QRegExp LABMEDICA_REGEX("[FfZz0-9\\*]+");
    const QRegExp DIGIT_REGEX("[0-9]+");
    const QRegExp DIGIT_ASTERISC_REGEX("[0-9\\*]+");
    const QRegExp VILLE_REGEX("[a-zA-Zâêîôûàéèù \\-\\*]+");
    const QRegExp SEXE_REGEX("[MFU]");
    const QRegExp REF_EXT_REGEX("[a-zA-Z0-9âêîôûàéèù \\-\\*]+");

    QString StringsUtils::toCamelCase(const QString& s) {
        QStringList parts = s.split(' ', QString::SkipEmptyParts);
        for (int i = 0; i < parts.size(); ++i) {
            parts[i].replace(0, 1, parts[i][0].toUpper());
        }

        return parts.join(" ");
    }

    bool StringsUtils::isNumber(const char* string) {
        int stringLen = strlen(string);
        int i;
        for (i = 0; i < stringLen; i++) {
            if (!isdigit(string[i])) { return false; }
        }
        return true;
    }

    bool StringsUtils::isMatchRefExt(const QString& str) {
        if (!str.isEmpty()) { return frlis::utilities::REF_EXT_REGEX.exactMatch(str); }
        return false;
    }

    bool StringsUtils::isMatchRefExt(const std::string& str) { return isMatchRefExt(QString::fromStdString(str)); }

    bool StringsUtils::isMatchSexe(const QString& str) {
        if (!str.isEmpty()) { return frlis::utilities::SEXE_REGEX.exactMatch(str); }
        return false;
    }

    bool StringsUtils::isMatchSexe(const std::string& str) { return isMatchSexe(QString::fromStdString(str)); }

    bool StringsUtils::isMatchVille(const QString& str) {
        if (!str.isEmpty()) { return frlis::utilities::VILLE_REGEX.exactMatch(str); }
        return false;
    }

    bool StringsUtils::isMatchVille(const std::string& str) { return isMatchVille(QString::fromStdString(str)); }

    bool StringsUtils::isMatchDigit(const QString& str) {
        if (!str.isEmpty()) { return frlis::utilities::DIGIT_REGEX.exactMatch(str); }
        return false;
    }

    bool StringsUtils::isMatchDigit(const std::string& str) { return isMatchDigit(QString::fromStdString(str)); }

    bool StringsUtils::isMatchDigitAndAsterisc(const QString& str) {
        if (!str.isEmpty()) { return frlis::utilities::DIGIT_ASTERISC_REGEX.exactMatch(str); }
        return false;
    }

    bool StringsUtils::isMatchDigitAndAsterisc(const std::string& str) { return isMatchDigitAndAsterisc(QString::fromStdString(str)); }

    bool StringsUtils::isMatchLabmedica(const QString& str) {
        if (!str.isEmpty()) { return frlis::utilities::LABMEDICA_REGEX.exactMatch(str); }
        return false;
    }

    bool StringsUtils::isMatchLabmedica(const std::string& str) { return isMatchLabmedica(QString::fromStdString(str)); }

    bool StringsUtils::isMatchNumSsv(const QString& str) {
        if (!str.isEmpty()) { return frlis::utilities::NUM_SSV_REGEX.exactMatch(str); }
        return false;
    }

    bool StringsUtils::isMatchNumSsv(const std::string& str) { return isMatchNumSsv(QString::fromStdString(str)); }

    bool StringsUtils::isMatchAlphanumeric(const QString& str) {
        if (!str.isEmpty()) { return frlis::utilities::ALPHANUMERIC_REGEX.exactMatch(str); }
        return false;
    }

    bool StringsUtils::isMatchAlphanumeric(const std::string& str) { return isMatchAlphanumeric(QString::fromStdString(str)); }

    bool StringsUtils::isMatchAlphanumericAndAsterisc(const QString& str) {
        if (!str.isEmpty()) { return frlis::utilities::ALPHANUMERIC_ASTERISC_REGEX.exactMatch(str); }
        return false;
    }

    bool StringsUtils::isMatchAlphanumericAndAsterisc(const std::string& str) {
        return isMatchAlphanumericAndAsterisc(QString::fromStdString(str));
    }

    bool StringsUtils::isMatchEmail(const QString& str) {
        if (!str.isEmpty()) { return frlis::utilities::EMAIL_REGEX.exactMatch(str); }
        return false;
    }

    bool StringsUtils::isMatchEmail(const std::string& str) { return isMatchEmail(QString::fromStdString(str)); }

    bool StringsUtils::isMatchNumeric(const QString& str) {
        if (!str.isEmpty()) { return frlis::utilities::NUMBER_REGEX.exactMatch(str); }
        return false;
    }

    bool StringsUtils::isMatchNumeric(const std::string& str) { return isMatchNumeric(QString::fromStdString(str)); }

    bool StringsUtils::isMatchDate(const QString& str) {
        if (!str.isEmpty()) { return frlis::utilities::DATE_REGEX.exactMatch(str); }
        return false;
    }

    bool StringsUtils::isMatchDate(const std::string& str) { return isMatchDate(QString::fromStdString(str)); }

    bool StringsUtils::isMatchHour(const QString& str) {
        if (!str.isEmpty()) { return frlis::utilities::HOUR_REGEX.exactMatch(str); }
        return false;
    }

    bool StringsUtils::isMatchHour(const std::string& str) { return isMatchHour(QString::fromStdString(str)); }

    bool StringsUtils::isMatchHourContainingH(const QString& str) {
        if (!str.isEmpty()) { return frlis::utilities::HOUR_REGEX_WITH_H.exactMatch(str); }
        return false;
    }

    bool StringsUtils::isMatchHourContainingH(const std::string& str) { return isMatchHourContainingH(QString::fromStdString(str)); }

    std::string StringsUtils::escape(const char* s) {
        std::string escaped(s);
        boost::replace_all(escaped, "'", "''");
        return escaped;
    }

    QString StringsUtils::qEscape(const char* s) {
        QString escaped(s);
        escaped.replace("'", "''", Qt::CaseInsensitive);
        return escaped;
    }

    QString StringsUtils::qEscape(const QString& s) {
        QString escaped(s);
        escaped.replace("'", "''", Qt::CaseInsensitive);
        return escaped;
    }

    std::string StringsUtils::escape(const std::string& s) { return boost::replace_all_copy(s, "'", "''"); }

    std::string StringsUtils::quote(const std::string& s) { return "'" + boost::replace_all_copy(s, "'", "''") + "'"; }

    std::string StringsUtils::replaceJoker(const std::string& s) { return boost::replace_all_copy(s, "*", "%"); }

    void StringsUtils::sort(QStringList& list) {
        int i;
        // remplacer les -> par des = pour que le tri fonctionne aussi sur la longueur de la chaine (valeur ascii '=' > '<')
        for (i = 0; i < list.size(); i++) {
            list[i].replace("->", "=");
        }
        list.sort();
        // remplacer les = par des -> retour à la normale
        for (i = 0; i < list.size(); i++) {
            list[i].replace("=", "->");
        }
    }

    QRegExp StringsUtils::getNumberSqlRegex() { return frlis::utilities::NUMBER_SQL_REGEX; }

    QString StringsUtils::getDateFormat() { return frlis::utilities::DATE_FORMAT; }

    QString StringsUtils::getDateTimeFormat() { return frlis::utilities::DATE_TIME_FORMAT; }

    QString StringsUtils::getDateSqlFormat() { return frlis::utilities::DATE_SQL_FORMAT; }

    std::string StringsUtils::trim(const std::string& str, const std::string& whitespace) {
        const auto strBegin = str.find_first_not_of(whitespace);
        if (strBegin == std::string::npos) {
            return "";  // no content
        }

        const auto strEnd   = str.find_last_not_of(whitespace);
        const auto strRange = strEnd - strBegin + 1;

        return str.substr(strBegin, strRange);
    }

    void StringsUtils::requiredAndNumber(const QJsonObject& params, const QString& key) {
        if (!params.contains(key)) {
            throw std::runtime_error(QStringLiteral("The service expects argument [%1] to be specified").arg(key).toStdString());
        }
        if (!params.value(key).isDouble()) {
            throw std::runtime_error(QStringLiteral("The service expects argument [%1] to be a number").arg(key).toStdString());
        }
    }

    void StringsUtils::requiredAndString(const QJsonObject& params, const QString& key) {
        if (!params.contains(key)) {
            throw std::runtime_error(QStringLiteral("The service expects argument [%1] to be specified").arg(key).toStdString());
        }
        if (!params.value(key).isString()) {
            throw std::runtime_error(QStringLiteral("The service expects argument [%1] to be a string").arg(key).toStdString());
        }
    }

    void StringsUtils::requiredAndBool(const QJsonObject& params, const QString& key) {
        if (!params.contains(key)) {
            throw std::runtime_error(QStringLiteral("The service expects argument [%1] to be specified").arg(key).toStdString());
        }
        if (!params.value(key).isBool()) {
            throw std::runtime_error(QStringLiteral("The service expects argument [%1] to be a boolean").arg(key).toStdString());
        }
    }

    void StringsUtils::requiredAndDate(const QJsonObject& params, const QString& key) {
        if (!params.contains(key)) {
            throw std::runtime_error(QStringLiteral("The service expects argument [%1] to be specified").arg(key).toStdString());
        }
        if (params.value(key).isNull() || !params.value(key).toVariant().canConvert<QDateTime>()) {
            throw std::runtime_error(QStringLiteral("The service expects argument [%1] to be a date").arg(key).toStdString());
        }
    }

    void StringsUtils::requiredAndObject(const QJsonObject& params, const QString& key) {
        if (!params.contains(key)) {
            throw std::runtime_error(QStringLiteral("The service expects argument [%1] to be specified").arg(key).toStdString());
        }
        if (!params.value(key).isObject()) {
            throw std::runtime_error(QStringLiteral("The service expects argument [%1] to be an object").arg(key).toStdString());
        }
    }

    void StringsUtils::requiredArray(const QJsonObject& params, const QString& key) {
        if (!params.contains(key)) {
            throw std::runtime_error(QStringLiteral("The service expects argument [%1] to be specified").arg(key).toStdString());
        }
        if (!params.value(key).isArray()) {
            throw std::runtime_error(QStringLiteral("The service expects argument [%1] to be an array").arg(key).toStdString());
        }
    }

    void StringsUtils::requiredNumberArray(const QJsonObject& params, const QString& key) {
        if (!params.contains(key)) {
            throw std::runtime_error(QStringLiteral("The service expects argument [%1] to be specified").arg(key).toStdString());
        }
        if (!params.value(key).isArray()) {
            throw std::runtime_error(
                QStringLiteral("The service expects argument [%1] to be an array of numbers").arg(key).toStdString());
        }

        const auto& arrayValue = params.value(key).toArray();
        if (std::any_of(arrayValue.begin(), arrayValue.end(), [](const QJsonValue& value) { return !value.isDouble(); })) {
            throw std::runtime_error(
                QStringLiteral("The service expects argument [%1] to be an array of numbers").arg(key).toStdString());
        }
    }

    void StringsUtils::requiredNonEmptyArray(const QJsonObject& params, const QString& key) {
        if (!params.contains(key)) {
            throw std::runtime_error(QStringLiteral("The service expects argument [%1] to be specified").arg(key).toStdString());
        }
        if (!params.value(key).isArray() || params.value(key).toArray().isEmpty()) {
            throw std::runtime_error(
                QStringLiteral("The service expects argument [%1] to be a non-empty array").arg(key).toStdString());
        }
    }

    void StringsUtils::requiredAndArray(const QJsonObject& params, const QString& key) {
        if (!params.contains(key) || !params.value(key).isArray()) {
            throw std::runtime_error(QStringLiteral("Le service attend la propriété '%1' de type array").arg(key).toStdString());
        }
    }

    void StringsUtils::optionalAndNumber(const QJsonObject& params, const QString& key, bool allowNull /* = false */) {
        if (params.contains(key) && !params.value(key).isDouble()) {
            if (!allowNull || !params.value(key).isNull()) {
                throw std::runtime_error(QStringLiteral("The service expects argument [%1] to be a number").arg(key).toStdString());
            }
        }
    }

    void StringsUtils::optionalAndString(const QJsonObject& params, const QString& key, bool allowNull /* = false */) {
        if (params.contains(key) && !params.value(key).isString()) {
            if (!allowNull || !params.value(key).isNull()) {
                throw std::runtime_error(QStringLiteral("The service expects argument [%1] to be a string").arg(key).toStdString());
            }
        }
    }

    void StringsUtils::optionalAndBool(const QJsonObject& params, const QString& key, bool allowNull /* = false */) {
        if (params.contains(key) && !params.value(key).isBool()) {
            if (!allowNull || !params.value(key).isNull()) {
                throw std::runtime_error(QStringLiteral("The service expects argument [%1] to be a boolean").arg(key).toStdString());
            }
        }
    }

    void StringsUtils::optionalAndDate(const QJsonObject& params, const QString& key, bool allowNull /* = false */) {
        if (params.contains(key) && (params.value(key).isNull() || !params.value(key).toVariant().canConvert<QDateTime>())) {
            if (!allowNull || !params.value(key).isNull()) {
                throw std::runtime_error(QStringLiteral("The service expects argument [%1] to be a date").arg(key).toStdString());
            }
        }
    }

    void StringsUtils::optionalAndObject(const QJsonObject& params, const QString& key, bool allowNull /* = false */) {
        if (params.contains(key) && !params.value(key).isObject()) {
            if (!allowNull || !params.value(key).isNull()) {
                throw std::runtime_error(QStringLiteral("The service expects argument [%1] to be an object").arg(key).toStdString());
            }
        }
    }

    void StringsUtils::optionalArray(const QJsonObject& params, const QString& key, bool allowNull /* = false */) {
        if (params.contains(key) && !params.value(key).isArray()) {
            if (!allowNull || !params.value(key).isNull()) {
                throw std::runtime_error(QStringLiteral("The service expects argument [%1] to be an array").arg(key).toStdString());
            }
        }
    }

    void StringsUtils::optionalNumberArray(const QJsonObject& params, const QString& key, bool allowNull /* = false */) {
        if (params.contains(key) && !params.value(key).isArray()) {
            if (!allowNull || !params.value(key).isNull()) {
                throw std::runtime_error(QStringLiteral("The service expects argument [%1] to be an array").arg(key).toStdString());
            }
        }

        const auto& arrayValue = params.value(key).toArray();
        if (std::any_of(arrayValue.begin(), arrayValue.end(), [&key](const QJsonValue& value) { return !value.isDouble(); })) {
            throw std::runtime_error(
                QStringLiteral("The service expects argument [%1] to be an array of numbers").arg(key).toStdString());
        }
    }

    void StringsUtils::optionalAndArray(const QJsonObject& params, const QString& key, bool allowNull /* = false */) {
        if (params.contains(key) && !params.value(key).isArray()) {
            if (!allowNull || !params.value(key).isNull()) {
                throw std::runtime_error(QStringLiteral("Le service attend la propriété '%1' de type array").arg(key).toStdString());
            }
        }
    }

    void StringsUtils::isNumericArray(const QJsonObject& params, const QString& key) {
        const auto& arrayValue = params.value(key).toArray();
        if (std::any_of(arrayValue.begin(), arrayValue.end(), [&key](const QJsonValue& value) { return !value.isDouble(); })) {
            throw std::runtime_error(
                QStringLiteral("Le service attend un array de number pour la propriété '%1'").arg(key).toStdString());
        }
    }

    void StringsUtils::isStringArray(const QJsonObject& params, const QString& key) {
        const auto& arrayValue = params.value(key).toArray();
        if (std::any_of(arrayValue.begin(), arrayValue.end(), [&key](const QJsonValue& value) { return !value.isString(); })) {
            throw std::runtime_error(
                QStringLiteral("Le service attend un array de string pour la propriété '%1'").arg(key).toStdString());
        }
    }

    QJsonValue StringsUtils::nullIfEmptyStr(const QString& val) {
        if (val.isEmpty()) { return QJsonValue(); }
        return val;
    }

    QString StringsUtils::normalizedStrOnlyAlphaNum(const QString& val) {
        QString asciiStr = fromLatin1ToAscii<true>(val);
        asciiStr.remove(QRegExp("[^a-zA-Z\\d\\s]"));  // remove all non alphanumeric
        return asciiStr.toLatin1();
    }

    static QString getSignSymbol(int64_t x) { return x >= 0 ? "" : "-"; }

    QString StringsUtils::getFormattedMoneyString(double doubleValue) {
        double roundedVal = doubleValue >= 0 ? doubleValue + 0.005 : doubleValue - 0.005;  // 34.456 => 34461 => 3446
        return getFormattedMoneyString(static_cast<int64_t>(roundedVal * 100));
    }

    QString StringsUtils::getFormattedMoneyString(int64_t valueInCents) {
        QStringList tmp;
        uint64_t    cents   = abs(valueInCents) % 100;
        uint64_t    entiers = abs(valueInCents) / 100;

        tmp << getSignSymbol(valueInCents);
        if (entiers >= 1000) {
            if (entiers >= 1000000) {
                tmp << QString::number(entiers / 1000000, 'f', 0);
                tmp << ",";
                tmp << QString("%1").arg((entiers % 1000000) / 1000, 3, 10, QLatin1Char('0'));
            } else {
                tmp << QString::number((entiers % 1000000) / 1000, 'f', 0);
            }
            tmp << ",";
            tmp << QString("%1").arg(entiers % 1000, 3, 10, QLatin1Char('0'));
        } else {
            tmp << QString::number(entiers % 1000, 'f', 0);
        }

        // ajout des cents
        tmp << ".";
        tmp << QString("%1").arg(cents, 2, 10, QLatin1Char('0'));

        return tmp.join("");
    }

    std::vector<std::string> StringsUtils::tokenize(const std::string& input, char seperator, char escape) {
        std::vector<std::string> output;

        std::string token;

        bool inEsc = false;
        for (char ch : input) {
            if (inEsc) {
                inEsc = false;
            } else if (ch == escape) {
                inEsc = true;
                continue;
            } else if (ch == seperator) {
                output.push_back(token);
                token = "";
                continue;
            }
            token += ch;
        }
        if (inEsc) { throw std::invalid_argument("Input string is invalid (terminating with escape char)"); }
        if (!token.empty()) { output.push_back(token); }
        return output;
    }

    std::string StringsUtils::replaceAll(std::string str, const std::string& from, const std::string& to) {
        size_t start_pos = 0;
        while ((start_pos = str.find(from, start_pos)) != std::string::npos) {
            str.replace(start_pos, from.length(), to);
            start_pos += to.length();  // Handles case where 'to' is a substring of 'from'
        }
        return str;
    }

    QString StringsUtils::substituteAccents(const QString& str) {
        const static QList<QString> accents = {"ä", "â", "à", "é", "è", "ê", "ë", "ï", "î", "ì", "ö", "ô", "ò", "ü", "û", "ù", "ç",
                                               "À", "Â", "Ä", "È", "É", "Ê", "Ë", "Ì", "Î", "Ï", "Ò", "Ô", "Ö", "Ù", "Û", "Ü", "Ç"};
        const static QList<QChar> substitute = {'a', 'a', 'a', 'e', 'e', 'e', 'e', 'i', 'i', 'i', 'o', 'o', 'o', 'u', 'u', 'u', 'c',
                                                'A', 'A', 'A', 'E', 'E', 'E', 'E', 'I', 'I', 'I', 'O', 'O', 'O', 'U', 'U', 'U', 'C'};
        QString                   temp       = str;
        for (int i = 0; i < accents.size(); ++i) {
            temp = temp.replace(accents[i], substitute[i], Qt::CaseInsensitive);
        }
        return temp;
    }

    std::vector<std::string> StringsUtils::split(const std::string& string, const std::string& delimiter) {
        std::vector<std::string> result{};
        auto split = QString::fromStdString(string).split(QString::fromStdString(delimiter), QString::SplitBehavior::SkipEmptyParts);

        for (const auto& element : split) {
            result.emplace_back(element.toStdString());
        }

        return result;
    }
}  // namespace frlis::utilities