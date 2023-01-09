/*
 * StringsUtils.hh
 *
 *  Créé le : 23/10/2017
 *      Auteur : Romain Macureau
 *
 *    methodes statiques utiles
 */

#pragma once

#include <ctype.h>
#include <stdio.h>
#include <string.h>
#include <time.h>

#include <array>
#include <exception>
#include <iostream>
#include <stdexcept>

#include <boost/algorithm/string.hpp>

#include <QtCore/qstring.h>
#include <QRegExp>
#include <QString>
#include <QFileInfo>
#include <QSqlQuery>



namespace frlis::utilities {

class StringsUtils {
 public:
  /**
   * Transform les premiere lettre d'une string en upperCase.
   *  i:e "string a modifier" => "String A Modifier"
   * @param s string a modifier
   * @return string modifier
   */
  static QString toCamelCase(const QString& s);

  /**
   * La chaine de caractères est-elle un nombre ?
   *
   * @param char*
   * @return boolean
   *
   */
  static bool isNumber(const char* string);

  /**
   * Echapper la chaîne de caractères : doubler les quotes '
   *
   * @param const char* s
   * @return QString la chaîne échappée
   *
   */
  static QString qEscape(const char* s);

  /**
   * Echapper la chaîne de caractères : doubler les quotes '
   *
   * @param QString s
   * @return QString la nouvelle chaîne échappée
   *
   */
  static QString qEscape(const QString& s);

  /**
   * Echapper la chaîne de caractères : doubler les quotes '
   *
   * @param const char* s
   * @return string la chaîne échappée
   *
   */
  static std::string escape(const char* s);

  /**
   * Echapper la chaîne de caractères : doubler les quotes '
   *
   * @param string& s
   * @return string une copie de la chaine échappée
   *
   */
  static std::string escape(const std::string& s);

  /**
   * Met des quotes ' et échappe la chaîne de caractères : doubler les quotes '
   *
   * @param string& s
   * @return string une copie de la chaine échapée et entre quotes
   *
   */
  static std::string quote(const std::string& s);

  /**
   * Remplacer les * par des %
   *
   * @param string& s
   * @return string une copie de la chaine
   *
   */
  static std::string replaceJoker(const std::string& s);

  /**
   *
   * Trier les QString par ordre alphabétique et du plus court au plus long
   *
   * @param QStringList& liste de QString à trier
   */
  static void sort(QStringList& list);

  /**
   * Get the default date format
   *
   * @returns QString
   */
  static QString getDateFormat();

  /**
   * Get the default date time format
   *
   * @returns QString
   */
  static QString getDateTimeFormat();

  /**
   * Formate un tableau de long en une string séparée par des virgules [1,2,4] => "1,2,4"
   * @param ids
   * @return String sans espaces au début et à la fin
   */
  static std::string trim(const std::string& str, const std::string& whitespace = " \t");

  static void requiredAndNumber(const QJsonObject& params, const QString& key);

  static void requiredAndString(const QJsonObject& params, const QString& key);

  static void requiredAndBool(const QJsonObject& params, const QString& key);

  static void requiredAndDate(const QJsonObject& params, const QString& key);

  static void requiredAndObject(const QJsonObject& params, const QString& key);

  static void requiredArray(const QJsonObject& params, const QString& key);

  static void requiredNumberArray(const QJsonObject& params, const QString& key);

  static void requiredNonEmptyArray(const QJsonObject& params, const QString& key);

  static void requiredAndArray(const QJsonObject& params, const QString& key);

  static void optionalAndNumber(const QJsonObject& params, const QString& key, bool allowNull = false);

  static void optionalAndString(const QJsonObject& params, const QString& key, bool allowNull = false);

  static void optionalAndBool(const QJsonObject& params, const QString& key, bool allowNull = false);

  static void optionalAndDate(const QJsonObject& params, const QString& key, bool allowNull = false);

  static void optionalAndObject(const QJsonObject& params, const QString& key, bool allowNull = false);

  static void optionalArray(const QJsonObject& params, const QString& key, bool allowNull = false);

  static void optionalNumberArray(const QJsonObject& params, const QString& key, bool allowNull = false);

  static void optionalAndArray(const QJsonObject& params, const QString& key, bool allowNull = false);

  static void isNumericArray(const QJsonObject& params, const QString& key);

  static void isStringArray(const QJsonObject& params, const QString& key);

  static QJsonValue nullIfEmptyStr(const QString& val);

  static QString normalizedStrOnlyAlphaNum(const QString &val);

  template <bool replacePunctuation>
  static QString fromLatin1ToAscii(const QString& s) {
    static QStringList diacriticLetters_{"Š", "Œ", "Ž", "š", "œ", "ž", "Ÿ", "¥", "µ", "À", "Á", "Â", "Ã", "Ä", "Å", "Æ", "Ç", "È",
                                         "É", "Ê", "Ë", "Ì", "Í", "Î", "Ï", "Ð", "Ñ", "Ò", "Ó", "Ô", "Õ", "Ö", "Ø", "Ù", "Ú", "Û",
                                         "Ü", "Ý", "ß", "à", "á", "â", "ã", "ä", "å", "æ", "ç", "è", "é", "ê", "ë", "ì", "í", "î",
                                         "ï", "ð", "ñ", "ò", "ó", "ô", "õ", "ö", "ø", "ù", "ú", "û", "ü", "ý", "ÿ"};
    static QStringList noDiacriticLetters_{"S", "OE", "Z", "s", "oe", "z", "Y", "Y", "u", "A",  "A", "A", "A", "A", "A", "AE", "C", "E",
                                           "E", "E",  "E", "I", "I",  "I", "I", "D", "N", "O",  "O", "O", "O", "O", "O", "U",  "U", "U",
                                           "U", "Y",  "s", "a", "a",  "a", "a", "a", "a", "ae", "c", "e", "e", "e", "e", "i",  "i", "i",
                                           "i", "o",  "n", "o", "o",  "o", "o", "o", "o", "u",  "u", "u", "u", "y", "y", " ",  " ", " "};

    static QStringList punctuation_{"-", "_", "'"};
    static QStringList noPunctuation_{" ", " ", " "};

    static QStringList diacriticLettersAndPunctuation_ = diacriticLetters_ + punctuation_;
    static QStringList noDiacriticLettersAndNoPunctuation_ = noDiacriticLetters_ + noPunctuation_;

    QString output = s;
    auto replace = [&output](QStringList& from, QStringList& to) {
      for (int i = 0; i < from.size(); ++i) {
        output = output.replace(from[i], to[i], Qt::CaseSensitive);
      }
      return output;
    };

    if constexpr (replacePunctuation) {
      return replace(diacriticLettersAndPunctuation_, noDiacriticLettersAndNoPunctuation_);
    } else {
      return replace(diacriticLetters_, noDiacriticLetters_);
    }
  }

  /**
   * Formate en string un montant en euro en ne gardant que deux décimales et en gérant les arrondis (arrondi supérieur en absolu)"
   * / ! \ Maximum 11 chiffres pour la valeur d'entrée
   *  @param doubleValue Valeur en euros
   *  @return String formatté correspondant au montant arrondi
   */
  static QString getFormattedMoneyString(double doubleValue);
  /**
   * Formate en string un montant en centimes en le transformant en montant en euro"
   * 1. on divie par 100 pour passer des centimes aux euros
   * 2. on le formate en string avec deux décimales
   *  / ! \ Maximum 11 chiffres pour la valeur d'entrée
   * @param valueInCents Valeur en centimes
   * @return String formatté correspondant au montant
   */
  static QString getFormattedMoneyString(int64_t valueInCents);

  /**
   * @brief Separe la string en input, selon le `separator`, tous en respectant le charactere d'escape
   * 
   * @param input : String a decouper
   * @param seperator : Char de separation
   * @param escape : Char d'escape (permet de ne pas separer)
   * @return std::vector<std::string> (liste de string decouper)
   */
  static std::vector<std::string> tokenize(const std::string& input, char seperator, char escape);

  /**
   * @brief Remplace toute les occurence dans une string
   * 
   * @param str : String a modifier
   * @param from : Substring a remplacer
   * @param to : Substring de remplacement
   * @return std::string 
   */
  static std::string replaceAll(std::string str, const std::string& from, const std::string& to);

  static bool isMatchNumeric(const QString& str);
  static bool isMatchNumeric(const std::string& str);

  static bool isMatchDate(const QString& str);
  static bool isMatchDate(const std::string& str);

  static bool isMatchHour(const QString& str);
  static bool isMatchHour(const std::string& str);

  static bool isMatchHourContainingH(const QString& str);
  static bool isMatchHourContainingH(const std::string& str);

  static bool isMatchEmail(const QString& str);
  static bool isMatchEmail(const std::string& str);

  static bool isMatchAlphanumeric(const QString& str);
  static bool isMatchAlphanumeric(const std::string& str);

  static bool isMatchAlphanumericAndAsterisc(const QString& str);
  static bool isMatchAlphanumericAndAsterisc(const std::string& str);

  static bool isMatchNumSsv(const QString& str);
  static bool isMatchNumSsv(const std::string& str);

  static bool isMatchLabmedica(const QString& str);
  static bool isMatchLabmedica(const std::string& str);

  static bool isMatchDigit(const QString& str);
  static bool isMatchDigit(const std::string& str);

  static bool isMatchDigitAndAsterisc(const QString& str);
  static bool isMatchDigitAndAsterisc(const std::string& str);

  static bool isMatchVille(const QString& str);
  static bool isMatchVille(const std::string& str);

  static bool isMatchRefExt(const QString& str);
  static bool isMatchRefExt(const std::string& str);

  static bool isMatchSexe(const QString& str);
  static bool isMatchSexe(const std::string& str);

  static QString getDateSqlFormat();
  static QRegExp getNumberSqlRegex();

  static QString substituteAccents(const QString& str);

  /**
   * Split a string with the given delimiter into several strings
   *
   * @param string - The string to extract the substrings from
   * @param delimiter - The substrings delimiter
   *
   * @return The substrings
   */
  static std::vector<std::string> split(const std::string& string, const std::string& delimiter);
};  // class StringUtils

}  // namespace frlis::utilities