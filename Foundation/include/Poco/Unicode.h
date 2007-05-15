//
// Unicode.h
//
// $Id: //poco/Main/Foundation/include/Poco/Unicode.h#1 $
//
// Library: Foundation
// Package: Text
// Module:  Unicode
//
// Definition of the Unicode class.
//
// Copyright (c) 2007, Applied Informatics Software Engineering GmbH.
// and Contributors.
//
// Permission is hereby granted, free of charge, to any person or organization
// obtaining a copy of the software and accompanying documentation covered by
// this license (the "Software") to use, reproduce, display, distribute,
// execute, and transmit the Software, and to prepare derivative works of the
// Software, and to permit third-parties to whom the Software is furnished to
// do so, all subject to the following:
// 
// The copyright notices in the Software and this entire statement, including
// the above license grant, this restriction and the following disclaimer,
// must be included in all copies of the Software, in whole or in part, and
// all derivative works of the Software, unless such copies or derivative
// works are solely in the form of machine-executable object code generated by
// a source language processor.
// 
// THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
// IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
// FITNESS FOR A PARTICULAR PURPOSE, TITLE AND NON-INFRINGEMENT. IN NO EVENT
// SHALL THE COPYRIGHT HOLDERS OR ANYONE DISTRIBUTING THE SOFTWARE BE LIABLE
// FOR ANY DAMAGES OR OTHER LIABILITY, WHETHER IN CONTRACT, TORT OR OTHERWISE,
// ARISING FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER
// DEALINGS IN THE SOFTWARE.
//


#ifndef Foundation_Unicode_INCLUDED
#define Foundation_Unicode_INCLUDED


#include "Poco/Foundation.h"


namespace Poco {


class Foundation_API Unicode
	/// This class contains enumerations and static
	/// utility functions for dealing with Unicode characters
	/// and their properties.
	///
	/// For more information on Unicode, see <http://www.unicode.org>.
	///
	/// The implementation is based on the Unicode support
	/// functions in PCRE.
{
public:
	// Implementation note: the following definitions must be kept
	// in sync with those from ucp.h (PCRE).
	enum CharacterCategory
		/// Unicode 5.0 character categories.
	{
		UCP_OTHER,
		UCP_LETTER,
		UCP_MARK,
		UCP_NUMBER,
		UCP_PUNCTUATION,
		UCP_SYMBOL,
		UCP_SEPARATOR
	};

	enum CharacterType
		/// Unicode 5.0 character types.
	{
		UCP_CONTROL,
		UCP_FORMAT,
		UCP_UNASSIGNED,
		UCP_PRIVATE_USE,
		UCP_SURROGATE,
		UCP_LOWER_CASE_LETTER,
		UCP_MODIFIER_LETTER,
		UCP_OTHER_LETTER,
		UCP_TITLE_CASE_LETTER,
		UCP_UPPER_CASE_LETTER,
		UCP_SPACING_MARK,
		UCP_ENCLOSING_MARK,
		UCP_NON_SPACING_MARK,
		UCP_DECIMAL_NUMBER,
		UCP_LETTER_NUMBER,
		UCP_OTHER_NUMBER,
		UCP_CONNECTOR_PUNCTUATION,
		UCP_DASH_PUNCTUATION,
		UCP_CLOSE_PUNCTUATION,
		UCP_FINAL_PUNCTUATION,
		UCP_INITIAL_PUNCTUATION,
		UCP_OTHER_PUNCTUATION,
		UCP_OPEN_PUNCTUATION,
		UCP_CURRENCY_SYMBOL,
		UCP_MODIFIER_SYMBOL,
		UCP_MATHEMATICAL_SYMBOL,
		UCP_OTHER_SYMBOL,
		UCP_LINE_SEPARATOR,
		UCP_PARAGRAPH_SEPARATOR,
		UCP_SPACE_SEPARATOR
	};
	
	enum Script
		/// Unicode 5.0 scripts.
	{
		UCP_ARABIC,
		UCP_ARMENIAN,
		UCP_BENGALI,
		UCP_BOPOMOFO,
		UCP_BRAILLE,
		UCP_BUGINESE,
		UCP_BUHID,
		UCP_CANADIAN_ABORIGINAL,
		UCP_CHEROKEE,
		UCP_COMMON,
		UCP_COPTIC,
		UCP_CYPRIOT,
		UCP_CYRILLIC,
		UCP_DESERET,
		UCP_DEVANAGARI,
		UCP_ETHIOPIC,
		UCP_GEORGIAN,
		UCP_GLAGOLITIC,
		UCP_GOTHIC,
		UCP_GREEK,
		UCP_GUJARATI,
		UCP_GURMUKHI,
		UCP_HAN,
		UCP_HANGUL,
		UCP_HANUNOO,
		UCP_HEBREW,
		UCP_HIRAGANA,
		UCP_INHERITED,
		UCP_KANNADA,
		UCP_KATAKANA,
		UCP_KHAROSHTHI,
		UCP_KHMER,
		UCP_LAO,
		UCP_LATIN,
		UCP_LIMBU,
		UCP_LINEAR_B,
		UCP_MALAYALAM,
		UCP_MONGOLIAN,
		UCP_MYANMAR,
		UCP_NEW_TAI_LUE,
		UCP_OGHAM,
		UCP_OLD_ITALIC,
		UCP_OLD_PERSIAN,
		UCP_ORIYA,
		UCP_OSMANYA,
		UCP_RUNIC,
		UCP_SHAVIAN,
		UCP_SINHALA,
		UCP_SYLOTI_NAGRI,
		UCP_SYRIAC,
		UCP_TAGALOG,
		UCP_TAGBANWA,
		UCP_TAI_LE,
		UCP_TAMIL,
		UCP_TELUGU,
		UCP_THAANA,
		UCP_THAI,
		UCP_TIBETAN,
		UCP_TIFINAGH,
		UCP_UGARITIC,
		UCP_YI,
		UCP_BALINESE,
		UCP_CUNEIFORM,
		UCP_NKO,
		UCP_PHAGS_PA,
		UCP_PHOENICIAN
	};
	
	struct CharacterProperties
		/// This structure holds the character properties
		/// of an Unicode character.
	{
		CharacterCategory category;
		CharacterType     type;
		Script            script;
	};

	static void properties(int ch, CharacterProperties& props);
		/// Return the Unicode character properties for the
		/// character with the given Unicode value.
		
	static bool isLower(int ch);
		/// Returns true iff the given character is a lowercase
		/// character.
		
	static bool isUpper(int ch);
		/// Returns true iff the given character is an uppercase
		/// character.
		
	static int toLower(int ch);
		/// If the given character is an uppercase character,
		/// return its lowercase counterpart, otherwise return
		/// the character.

	static int toUpper(int ch);
		/// If the given character is a lowercase character,
		/// return its uppercase counterpart, otherwise return
		/// the character.
};


} // namespace Poco


#endif // Foundation_Unicode_INCLUDED