// A Bison parser, made by GNU Bison 3.4.1.

// Skeleton implementation for Bison LALR(1) parsers in C++

// Copyright (C) 2002-2015, 2018-2019 Free Software Foundation, Inc.

// This program is free software: you can redistribute it and/or modify
// it under the terms of the GNU General Public License as published by
// the Free Software Foundation, either version 3 of the License, or
// (at your option) any later version.

// This program is distributed in the hope that it will be useful,
// but WITHOUT ANY WARRANTY; without even the implied warranty of
// MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
// GNU General Public License for more details.

// You should have received a copy of the GNU General Public License
// along with this program.  If not, see <http://www.gnu.org/licenses/>.

// As a special exception, you may create a larger work that contains
// part or all of the Bison parser skeleton and distribute that work
// under terms of your choice, so long as that work isn't itself a
// parser generator using the skeleton or a modified version thereof
// as a parser skeleton.  Alternatively, if you modify or redistribute
// the parser skeleton itself, you may (at your option) remove this
// special exception, which will cause the skeleton and the resulting
// Bison output files to be licensed under the GNU General Public
// License without this special exception.

// This special exception was added by the Free Software Foundation in
// version 2.2 of Bison.

// Undocumented macros, especially those whose name start with YY_,
// are private implementation details.  Do not rely on them.





#include "grammar.hh"


// Unqualified %code blocks.
#line 32 "lake.yy"

   #include <iostream>
   #include <cstdlib>
   #include <fstream>

   /* include for interoperation between scanner/parser */
   #include "scanner.hpp"

#undef yylex
#define yylex scanner.yylex

#line 57 "parser.cc"


#ifndef YY_
# if defined YYENABLE_NLS && YYENABLE_NLS
#  if ENABLE_NLS
#   include <libintl.h> // FIXME: INFRINGES ON USER NAME SPACE.
#   define YY_(msgid) dgettext ("bison-runtime", msgid)
#  endif
# endif
# ifndef YY_
#  define YY_(msgid) msgid
# endif
#endif

// Whether we are compiled with exception support.
#ifndef YY_EXCEPTIONS
# if defined __GNUC__ && !defined __EXCEPTIONS
#  define YY_EXCEPTIONS 0
# else
#  define YY_EXCEPTIONS 1
# endif
#endif



// Suppress unused-variable warnings by "using" E.
#define YYUSE(E) ((void) (E))

// Enable debugging if requested.
#if YYDEBUG

// A pseudo ostream that takes yydebug_ into account.
# define YYCDEBUG if (yydebug_) (*yycdebug_)

# define YY_SYMBOL_PRINT(Title, Symbol)         \
  do {                                          \
    if (yydebug_)                               \
    {                                           \
      *yycdebug_ << Title << ' ';               \
      yy_print_ (*yycdebug_, Symbol);           \
      *yycdebug_ << '\n';                       \
    }                                           \
  } while (false)

# define YY_REDUCE_PRINT(Rule)          \
  do {                                  \
    if (yydebug_)                       \
      yy_reduce_print_ (Rule);          \
  } while (false)

# define YY_STACK_PRINT()               \
  do {                                  \
    if (yydebug_)                       \
      yystack_print_ ();                \
  } while (false)

#else // !YYDEBUG

# define YYCDEBUG if (false) std::cerr
# define YY_SYMBOL_PRINT(Title, Symbol)  YYUSE (Symbol)
# define YY_REDUCE_PRINT(Rule)           static_cast<void> (0)
# define YY_STACK_PRINT()                static_cast<void> (0)

#endif // !YYDEBUG

#define yyerrok         (yyerrstatus_ = 0)
#define yyclearin       (yyla.clear ())

#define YYACCEPT        goto yyacceptlab
#define YYABORT         goto yyabortlab
#define YYERROR         goto yyerrorlab
#define YYRECOVERING()  (!!yyerrstatus_)

#line 5 "lake.yy"
namespace lake {
#line 133 "parser.cc"


  /// Build a parser object.
  Parser::Parser (lake::Scanner  &scanner_yyarg, lake::ProgramNode** root_yyarg)
    :
#if YYDEBUG
      yydebug_ (false),
      yycdebug_ (&std::cerr),
#endif
      scanner (scanner_yyarg),
      root (root_yyarg)
  {}

  Parser::~Parser ()
  {}

  Parser::syntax_error::~syntax_error () YY_NOEXCEPT YY_NOTHROW
  {}

  /*---------------.
  | Symbol types.  |
  `---------------*/

  // basic_symbol.
#if 201103L <= YY_CPLUSPLUS
  template <typename Base>
  Parser::basic_symbol<Base>::basic_symbol (basic_symbol&& that)
    : Base (std::move (that))
    , value (std::move (that.value))
  {}
#endif

  template <typename Base>
  Parser::basic_symbol<Base>::basic_symbol (const basic_symbol& that)
    : Base (that)
    , value (that.value)
  {}


  /// Constructor for valueless symbols.
  template <typename Base>
  Parser::basic_symbol<Base>::basic_symbol (typename Base::kind_type t)
    : Base (t)
    , value ()
  {}

  template <typename Base>
  Parser::basic_symbol<Base>::basic_symbol (typename Base::kind_type t, YY_RVREF (semantic_type) v)
    : Base (t)
    , value (YY_MOVE (v))
  {}

  template <typename Base>
  bool
  Parser::basic_symbol<Base>::empty () const YY_NOEXCEPT
  {
    return Base::type_get () == empty_symbol;
  }

  template <typename Base>
  void
  Parser::basic_symbol<Base>::move (basic_symbol& s)
  {
    super_type::move (s);
    value = YY_MOVE (s.value);
  }

  // by_type.
  Parser::by_type::by_type ()
    : type (empty_symbol)
  {}

#if 201103L <= YY_CPLUSPLUS
  Parser::by_type::by_type (by_type&& that)
    : type (that.type)
  {
    that.clear ();
  }
#endif

  Parser::by_type::by_type (const by_type& that)
    : type (that.type)
  {}

  Parser::by_type::by_type (token_type t)
    : type (yytranslate_ (t))
  {}

  void
  Parser::by_type::clear ()
  {
    type = empty_symbol;
  }

  void
  Parser::by_type::move (by_type& that)
  {
    type = that.type;
    that.clear ();
  }

  int
  Parser::by_type::type_get () const YY_NOEXCEPT
  {
    return type;
  }


  // by_state.
  Parser::by_state::by_state () YY_NOEXCEPT
    : state (empty_state)
  {}

  Parser::by_state::by_state (const by_state& that) YY_NOEXCEPT
    : state (that.state)
  {}

  void
  Parser::by_state::clear () YY_NOEXCEPT
  {
    state = empty_state;
  }

  void
  Parser::by_state::move (by_state& that)
  {
    state = that.state;
    that.clear ();
  }

  Parser::by_state::by_state (state_type s) YY_NOEXCEPT
    : state (s)
  {}

  Parser::symbol_number_type
  Parser::by_state::type_get () const YY_NOEXCEPT
  {
    if (state == empty_state)
      return empty_symbol;
    else
      return yystos_[state];
  }

  Parser::stack_symbol_type::stack_symbol_type ()
  {}

  Parser::stack_symbol_type::stack_symbol_type (YY_RVREF (stack_symbol_type) that)
    : super_type (YY_MOVE (that.state), YY_MOVE (that.value))
  {
#if 201103L <= YY_CPLUSPLUS
    // that is emptied.
    that.state = empty_state;
#endif
  }

  Parser::stack_symbol_type::stack_symbol_type (state_type s, YY_MOVE_REF (symbol_type) that)
    : super_type (s, YY_MOVE (that.value))
  {
    // that is emptied.
    that.type = empty_symbol;
  }

#if YY_CPLUSPLUS < 201103L
  Parser::stack_symbol_type&
  Parser::stack_symbol_type::operator= (stack_symbol_type& that)
  {
    state = that.state;
    value = that.value;
    // that is emptied.
    that.state = empty_state;
    return *this;
  }
#endif

  template <typename Base>
  void
  Parser::yy_destroy_ (const char* yymsg, basic_symbol<Base>& yysym) const
  {
    if (yymsg)
      YY_SYMBOL_PRINT (yymsg, yysym);

    // User destructor.
    YYUSE (yysym.type_get ());
  }

#if YYDEBUG
  template <typename Base>
  void
  Parser::yy_print_ (std::ostream& yyo,
                                     const basic_symbol<Base>& yysym) const
  {
    std::ostream& yyoutput = yyo;
    YYUSE (yyoutput);
    symbol_number_type yytype = yysym.type_get ();
#if defined __GNUC__ && ! defined __clang__ && ! defined __ICC && __GNUC__ * 100 + __GNUC_MINOR__ <= 408
    // Avoid a (spurious) G++ 4.8 warning about "array subscript is
    // below array bounds".
    if (yysym.empty ())
      std::abort ();
#endif
    yyo << (yytype < yyntokens_ ? "token" : "nterm")
        << ' ' << yytname_[yytype] << " (";
    YYUSE (yytype);
    yyo << ')';
  }
#endif

  void
  Parser::yypush_ (const char* m, YY_MOVE_REF (stack_symbol_type) sym)
  {
    if (m)
      YY_SYMBOL_PRINT (m, sym);
    yystack_.push (YY_MOVE (sym));
  }

  void
  Parser::yypush_ (const char* m, state_type s, YY_MOVE_REF (symbol_type) sym)
  {
#if 201103L <= YY_CPLUSPLUS
    yypush_ (m, stack_symbol_type (s, std::move (sym)));
#else
    stack_symbol_type ss (s, sym);
    yypush_ (m, ss);
#endif
  }

  void
  Parser::yypop_ (int n)
  {
    yystack_.pop (n);
  }

#if YYDEBUG
  std::ostream&
  Parser::debug_stream () const
  {
    return *yycdebug_;
  }

  void
  Parser::set_debug_stream (std::ostream& o)
  {
    yycdebug_ = &o;
  }


  Parser::debug_level_type
  Parser::debug_level () const
  {
    return yydebug_;
  }

  void
  Parser::set_debug_level (debug_level_type l)
  {
    yydebug_ = l;
  }
#endif // YYDEBUG

  Parser::state_type
  Parser::yy_lr_goto_state_ (state_type yystate, int yysym)
  {
    int yyr = yypgoto_[yysym - yyntokens_] + yystate;
    if (0 <= yyr && yyr <= yylast_ && yycheck_[yyr] == yystate)
      return yytable_[yyr];
    else
      return yydefgoto_[yysym - yyntokens_];
  }

  bool
  Parser::yy_pact_value_is_default_ (int yyvalue)
  {
    return yyvalue == yypact_ninf_;
  }

  bool
  Parser::yy_table_value_is_error_ (int yyvalue)
  {
    return yyvalue == yytable_ninf_;
  }

  int
  Parser::operator() ()
  {
    return parse ();
  }

  int
  Parser::parse ()
  {
    // State.
    int yyn;
    /// Length of the RHS of the rule being reduced.
    int yylen = 0;

    // Error handling.
    int yynerrs_ = 0;
    int yyerrstatus_ = 0;

    /// The lookahead symbol.
    symbol_type yyla;

    /// The return value of parse ().
    int yyresult;

#if YY_EXCEPTIONS
    try
#endif // YY_EXCEPTIONS
      {
    YYCDEBUG << "Starting parse\n";


    /* Initialize the stack.  The initial state will be set in
       yynewstate, since the latter expects the semantical and the
       location values to have been already stored, initialize these
       stacks with a primary value.  */
    yystack_.clear ();
    yypush_ (YY_NULLPTR, 0, YY_MOVE (yyla));

  /*-----------------------------------------------.
  | yynewstate -- push a new symbol on the stack.  |
  `-----------------------------------------------*/
  yynewstate:
    YYCDEBUG << "Entering state " << yystack_[0].state << '\n';

    // Accept?
    if (yystack_[0].state == yyfinal_)
      YYACCEPT;

    goto yybackup;


  /*-----------.
  | yybackup.  |
  `-----------*/
  yybackup:
    // Try to take a decision without lookahead.
    yyn = yypact_[yystack_[0].state];
    if (yy_pact_value_is_default_ (yyn))
      goto yydefault;

    // Read a lookahead token.
    if (yyla.empty ())
      {
        YYCDEBUG << "Reading a token: ";
#if YY_EXCEPTIONS
        try
#endif // YY_EXCEPTIONS
          {
            yyla.type = yytranslate_ (yylex (&yyla.value));
          }
#if YY_EXCEPTIONS
        catch (const syntax_error& yyexc)
          {
            YYCDEBUG << "Caught exception: " << yyexc.what() << '\n';
            error (yyexc);
            goto yyerrlab1;
          }
#endif // YY_EXCEPTIONS
      }
    YY_SYMBOL_PRINT ("Next token is", yyla);

    /* If the proper action on seeing token YYLA.TYPE is to reduce or
       to detect an error, take that action.  */
    yyn += yyla.type_get ();
    if (yyn < 0 || yylast_ < yyn || yycheck_[yyn] != yyla.type_get ())
      goto yydefault;

    // Reduce or error.
    yyn = yytable_[yyn];
    if (yyn <= 0)
      {
        if (yy_table_value_is_error_ (yyn))
          goto yyerrlab;
        yyn = -yyn;
        goto yyreduce;
      }

    // Count tokens shifted since error; after three, turn off error status.
    if (yyerrstatus_)
      --yyerrstatus_;

    // Shift the lookahead token.
    yypush_ ("Shifting", yyn, YY_MOVE (yyla));
    goto yynewstate;


  /*-----------------------------------------------------------.
  | yydefault -- do the default action for the current state.  |
  `-----------------------------------------------------------*/
  yydefault:
    yyn = yydefact_[yystack_[0].state];
    if (yyn == 0)
      goto yyerrlab;
    goto yyreduce;


  /*-----------------------------.
  | yyreduce -- do a reduction.  |
  `-----------------------------*/
  yyreduce:
    yylen = yyr2_[yyn];
    {
      stack_symbol_type yylhs;
      yylhs.state = yy_lr_goto_state_ (yystack_[yylen].state, yyr1_[yyn]);
      /* If YYLEN is nonzero, implement the default value of the
         action: '$$ = $1'.  Otherwise, use the top of the stack.

         Otherwise, the following line sets YYLHS.VALUE to garbage.
         This behavior is undocumented and Bison users should not rely
         upon it.  */
      if (yylen)
        yylhs.value = yystack_[yylen - 1].value;
      else
        yylhs.value = yystack_[0].value;


      // Perform the reduction.
      YY_REDUCE_PRINT (yyn);
#if YY_EXCEPTIONS
      try
#endif // YY_EXCEPTIONS
        {
          switch (yyn)
            {
  case 2:
#line 163 "lake.yy"
    {
		   (yylhs.value.programNode) = new ProgramNode(new DeclListNode((yystack_[0].value.declList)));
		   *root = (yylhs.value.programNode);
		   }
#line 565 "parser.cc"
    break;

  case 3:
#line 169 "lake.yy"
    {
			 (yystack_[1].value.declList)->push_back((yystack_[0].value.declNode));
			 (yylhs.value.declList) = (yystack_[1].value.declList);
			 }
#line 574 "parser.cc"
    break;

  case 4:
#line 173 "lake.yy"
    {
			(yylhs.value.declList) = new std::list<DeclNode *>();
			}
#line 582 "parser.cc"
    break;

  case 5:
#line 178 "lake.yy"
    {
		(yylhs.value.declNode) = (yystack_[0].value.varDeclNode);
		}
#line 590 "parser.cc"
    break;

  case 6:
#line 181 "lake.yy"
    {
    (yylhs.value.declNode) = (yystack_[0].value.fnDecl);
    }
#line 598 "parser.cc"
    break;

  case 7:
#line 184 "lake.yy"
    {
		(yylhs.value.varDeclNode) = new VarDeclNode((yystack_[2].value.typeNode), (yystack_[1].value.idNode));
			    }
#line 606 "parser.cc"
    break;

  case 8:
#line 187 "lake.yy"
    {
  (yylhs.value.fnDecl) = new FnDeclNode((yystack_[3].value.typeNode), (yystack_[2].value.idNode), (yystack_[1].value.formalsType), (yystack_[0].value.fnBody));
}
#line 614 "parser.cc"
    break;

  case 9:
#line 190 "lake.yy"
    {
  (yylhs.value.formalsType) = new FormalsListNode(new std::list<FormalDeclNode*> ());
}
#line 622 "parser.cc"
    break;

  case 10:
#line 193 "lake.yy"
    {
  (yylhs.value.formalsType) = new FormalsListNode((yystack_[1].value.formalsList));
  }
#line 630 "parser.cc"
    break;

  case 11:
#line 196 "lake.yy"
    {
  (yylhs.value.formalsList) = new std::list<FormalDeclNode*>;
  (yylhs.value.formalsList)->push_back((yystack_[0].value.formalDecl));
}
#line 639 "parser.cc"
    break;

  case 12:
#line 200 "lake.yy"
    {
  (yystack_[0].value.formalsList)->push_front((yystack_[2].value.formalDecl));
  (yylhs.value.formalsList) = (yystack_[0].value.formalsList);
  }
#line 648 "parser.cc"
    break;

  case 13:
#line 204 "lake.yy"
    {
  (yylhs.value.formalDecl) = new FormalDeclNode((yystack_[1].value.typeNode), (yystack_[0].value.idNode));
}
#line 656 "parser.cc"
    break;

  case 14:
#line 207 "lake.yy"
    {
  (yylhs.value.fnBody) = new FnBodyNode((yystack_[2].value.declList), (yystack_[1].value.stmtList));
}
#line 664 "parser.cc"
    break;

  case 15:
#line 210 "lake.yy"
    {
  (yylhs.value.stmtList) = (yystack_[1].value.stmtList);
  (yystack_[1].value.stmtList)->push_back((yystack_[0].value.stmtNode));
}
#line 673 "parser.cc"
    break;

  case 16:
#line 214 "lake.yy"
    {
  (yylhs.value.stmtList) = new std::list<StmtNode*> ();
  }
#line 681 "parser.cc"
    break;

  case 17:
#line 217 "lake.yy"
    {
  (yylhs.value.stmtNode) = new AssignStmtNode((yystack_[1].value.assignNode));
  }
#line 689 "parser.cc"
    break;

  case 18:
#line 220 "lake.yy"
    {
  (yylhs.value.stmtNode) = new PostIncStmtNode((yystack_[2].value.exp));
  }
#line 697 "parser.cc"
    break;

  case 19:
#line 223 "lake.yy"
    {
  (yylhs.value.stmtNode) = new PostDecStmtNode((yystack_[2].value.exp));
  }
#line 705 "parser.cc"
    break;

  case 20:
#line 226 "lake.yy"
    {
  (yylhs.value.stmtNode) = new ReadStmtNode((yystack_[1].value.exp));
  }
#line 713 "parser.cc"
    break;

  case 21:
#line 229 "lake.yy"
    {
  (yylhs.value.stmtNode) = new WriteStmtNode((yystack_[1].value.exp));
  }
#line 721 "parser.cc"
    break;

  case 22:
#line 232 "lake.yy"
    {
  (yylhs.value.stmtNode) = new IfStmtNode((yystack_[5].value.exp), (yystack_[2].value.declList), (yystack_[1].value.stmtList));
  }
#line 729 "parser.cc"
    break;

  case 23:
#line 235 "lake.yy"
    {
  (yylhs.value.stmtNode) = new IfElseStmtNode((yystack_[10].value.exp), (yystack_[7].value.declList), (yystack_[6].value.stmtList), (yystack_[2].value.declList), (yystack_[1].value.stmtList));
  }
#line 737 "parser.cc"
    break;

  case 24:
#line 238 "lake.yy"
    {
  (yylhs.value.stmtNode) = new WhileStmtNode((yystack_[5].value.exp), (yystack_[2].value.declList), (yystack_[1].value.stmtList));
  }
#line 745 "parser.cc"
    break;

  case 25:
#line 241 "lake.yy"
    {
  (yylhs.value.stmtNode) = new ReturnStmtNode((yystack_[2].value.tokenValue), (yystack_[1].value.exp));
  }
#line 753 "parser.cc"
    break;

  case 26:
#line 244 "lake.yy"
    {
  (yylhs.value.stmtNode) = new ReturnStmtNode((yystack_[1].value.tokenValue), nullptr);
  }
#line 761 "parser.cc"
    break;

  case 27:
#line 247 "lake.yy"
    {
  (yylhs.value.stmtNode) = new CallStmtNode((yystack_[1].value.callNode));
  }
#line 769 "parser.cc"
    break;

  case 28:
#line 250 "lake.yy"
    {
  (yylhs.value.assignNode) = new AssignNode((yystack_[2].value.exp), (yystack_[0].value.exp));
  }
#line 777 "parser.cc"
    break;

  case 29:
#line 253 "lake.yy"
    {
  (yylhs.value.exp) = new PlusNode((yystack_[2].value.exp), (yystack_[0].value.exp));
  }
#line 785 "parser.cc"
    break;

  case 30:
#line 256 "lake.yy"
    {
  (yylhs.value.exp) = new MinusNode((yystack_[2].value.exp), (yystack_[0].value.exp));
  }
#line 793 "parser.cc"
    break;

  case 31:
#line 259 "lake.yy"
    {
  (yylhs.value.exp) = new TimesNode((yystack_[2].value.exp), (yystack_[0].value.exp));
  }
#line 801 "parser.cc"
    break;

  case 32:
#line 262 "lake.yy"
    {
  (yylhs.value.exp) = new DivideNode((yystack_[2].value.exp), (yystack_[0].value.exp));
  }
#line 809 "parser.cc"
    break;

  case 33:
#line 265 "lake.yy"
    {
  (yylhs.value.exp) = new NotNode((yystack_[0].value.exp));
  }
#line 817 "parser.cc"
    break;

  case 34:
#line 268 "lake.yy"
    {
  (yylhs.value.exp) = new AndNode((yystack_[2].value.exp), (yystack_[0].value.exp));
  }
#line 825 "parser.cc"
    break;

  case 35:
#line 271 "lake.yy"
    {
  (yylhs.value.exp) = new OrNode((yystack_[2].value.exp), (yystack_[0].value.exp));
  }
#line 833 "parser.cc"
    break;

  case 36:
#line 274 "lake.yy"
    {
  (yylhs.value.exp) = new EqualsNode((yystack_[2].value.exp), (yystack_[0].value.exp));
  }
#line 841 "parser.cc"
    break;

  case 37:
#line 277 "lake.yy"
    {
  (yylhs.value.exp) = new NotEqualsNode((yystack_[2].value.exp), (yystack_[0].value.exp));
  }
#line 849 "parser.cc"
    break;

  case 38:
#line 280 "lake.yy"
    {
  (yylhs.value.exp) = new LessNode((yystack_[2].value.exp), (yystack_[0].value.exp));
  }
#line 857 "parser.cc"
    break;

  case 39:
#line 283 "lake.yy"
    {
  (yylhs.value.exp) = new GreaterNode((yystack_[2].value.exp), (yystack_[0].value.exp));
  }
#line 865 "parser.cc"
    break;

  case 40:
#line 286 "lake.yy"
    {
  (yylhs.value.exp) = new LessEqNode((yystack_[2].value.exp), (yystack_[0].value.exp));
  }
#line 873 "parser.cc"
    break;

  case 41:
#line 289 "lake.yy"
    {
  (yylhs.value.exp) = new GreaterEqNode((yystack_[2].value.exp), (yystack_[0].value.exp));
  }
#line 881 "parser.cc"
    break;

  case 42:
#line 292 "lake.yy"
    {
  (yylhs.value.exp) = new UnaryMinusNode((yystack_[0].value.exp));
  }
#line 889 "parser.cc"
    break;

  case 43:
#line 295 "lake.yy"
    {
  (yylhs.value.exp) = (yystack_[0].value.exp);
  }
#line 897 "parser.cc"
    break;

  case 44:
#line 298 "lake.yy"
    {
  (yylhs.value.exp) = (yystack_[0].value.exp);
  }
#line 905 "parser.cc"
    break;

  case 45:
#line 301 "lake.yy"
    {
  (yylhs.value.exp) = new IntLitNode((yystack_[0].value.intTokenValue));
  }
#line 913 "parser.cc"
    break;

  case 46:
#line 304 "lake.yy"
    {
  (yylhs.value.exp) = new StrLitNode((yystack_[0].value.strTokenValue));
  }
#line 921 "parser.cc"
    break;

  case 47:
#line 307 "lake.yy"
    {
  (yylhs.value.exp) = new TrueNode((yystack_[0].value.tokenValue));
  }
#line 929 "parser.cc"
    break;

  case 48:
#line 310 "lake.yy"
    {
  (yylhs.value.exp) = new FalseNode((yystack_[0].value.tokenValue));
  }
#line 937 "parser.cc"
    break;

  case 49:
#line 313 "lake.yy"
    {
  (yylhs.value.exp) = (yystack_[1].value.exp);
  }
#line 945 "parser.cc"
    break;

  case 50:
#line 316 "lake.yy"
    {
  (yylhs.value.exp) = (yystack_[0].value.callNode);
  }
#line 953 "parser.cc"
    break;

  case 51:
#line 319 "lake.yy"
    {
  //no args fn call
  (yylhs.value.callNode) = new CallExpNode((yystack_[2].value.idNode), new std::list<ExpNode*>());
  }
#line 962 "parser.cc"
    break;

  case 52:
#line 323 "lake.yy"
    {
  //with args fn call
  (yylhs.value.callNode) = new CallExpNode((yystack_[3].value.idNode), new std::list<ExpNode*>((yystack_[1].value.expList)));
  }
#line 971 "parser.cc"
    break;

  case 53:
#line 327 "lake.yy"
    {
  (yylhs.value.expList) = new std::list<ExpNode*> ();
  (yylhs.value.expList)->push_back((yystack_[0].value.exp));
  }
#line 980 "parser.cc"
    break;

  case 54:
#line 331 "lake.yy"
    {
  (yylhs.value.expList) = (yystack_[2].value.expList);
  (yylhs.value.expList)->push_back((yystack_[0].value.exp));
  }
#line 989 "parser.cc"
    break;

  case 55:
#line 335 "lake.yy"
    {
  (yylhs.value.typeNode) = (yystack_[1].value.typeNode);
  (yylhs.value.typeNode)->indirDepth = (yystack_[0].value.counterTrans);
  }
#line 998 "parser.cc"
    break;

  case 56:
#line 339 "lake.yy"
    {
  (yylhs.value.typeNode) = new IntNode((yystack_[0].value.tokenValue));
  }
#line 1006 "parser.cc"
    break;

  case 57:
#line 342 "lake.yy"
    {
  (yylhs.value.typeNode) = new BoolNode((yystack_[0].value.tokenValue));
  }
#line 1014 "parser.cc"
    break;

  case 58:
#line 345 "lake.yy"
    {
  (yylhs.value.typeNode) = new VoidNode((yystack_[0].value.tokenValue));
  }
#line 1022 "parser.cc"
    break;

  case 59:
#line 348 "lake.yy"
    {
  (yylhs.value.counterTrans) = (yystack_[1].value.counterTrans) + 1;
  }
#line 1030 "parser.cc"
    break;

  case 60:
#line 351 "lake.yy"
    {
  (yylhs.value.counterTrans) = 0;
  }
#line 1038 "parser.cc"
    break;

  case 61:
#line 354 "lake.yy"
    {
  (yylhs.value.exp) = new IdNode((yystack_[0].value.idNode));
  }
#line 1046 "parser.cc"
    break;

  case 62:
#line 357 "lake.yy"
    {
  (yystack_[0].value.exp)->derefDepth += 1;
  (yylhs.value.exp) = (yystack_[0].value.exp);
  }
#line 1055 "parser.cc"
    break;

  case 63:
#line 361 "lake.yy"
    { (yylhs.value.idNode) = new IdNode((yystack_[0].value.idTokenValue)); }
#line 1061 "parser.cc"
    break;


#line 1065 "parser.cc"

            default:
              break;
            }
        }
#if YY_EXCEPTIONS
      catch (const syntax_error& yyexc)
        {
          YYCDEBUG << "Caught exception: " << yyexc.what() << '\n';
          error (yyexc);
          YYERROR;
        }
#endif // YY_EXCEPTIONS
      YY_SYMBOL_PRINT ("-> $$ =", yylhs);
      yypop_ (yylen);
      yylen = 0;
      YY_STACK_PRINT ();

      // Shift the result of the reduction.
      yypush_ (YY_NULLPTR, YY_MOVE (yylhs));
    }
    goto yynewstate;


  /*--------------------------------------.
  | yyerrlab -- here on detecting error.  |
  `--------------------------------------*/
  yyerrlab:
    // If not already recovering from an error, report this error.
    if (!yyerrstatus_)
      {
        ++yynerrs_;
        error (yysyntax_error_ (yystack_[0].state, yyla));
      }


    if (yyerrstatus_ == 3)
      {
        /* If just tried and failed to reuse lookahead token after an
           error, discard it.  */

        // Return failure if at end of input.
        if (yyla.type_get () == yyeof_)
          YYABORT;
        else if (!yyla.empty ())
          {
            yy_destroy_ ("Error: discarding", yyla);
            yyla.clear ();
          }
      }

    // Else will try to reuse lookahead token after shifting the error token.
    goto yyerrlab1;


  /*---------------------------------------------------.
  | yyerrorlab -- error raised explicitly by YYERROR.  |
  `---------------------------------------------------*/
  yyerrorlab:
    /* Pacify compilers when the user code never invokes YYERROR and
       the label yyerrorlab therefore never appears in user code.  */
    if (false)
      YYERROR;

    /* Do not reclaim the symbols of the rule whose action triggered
       this YYERROR.  */
    yypop_ (yylen);
    yylen = 0;
    goto yyerrlab1;


  /*-------------------------------------------------------------.
  | yyerrlab1 -- common code for both syntax error and YYERROR.  |
  `-------------------------------------------------------------*/
  yyerrlab1:
    yyerrstatus_ = 3;   // Each real token shifted decrements this.
    {
      stack_symbol_type error_token;
      for (;;)
        {
          yyn = yypact_[yystack_[0].state];
          if (!yy_pact_value_is_default_ (yyn))
            {
              yyn += yyterror_;
              if (0 <= yyn && yyn <= yylast_ && yycheck_[yyn] == yyterror_)
                {
                  yyn = yytable_[yyn];
                  if (0 < yyn)
                    break;
                }
            }

          // Pop the current state because it cannot handle the error token.
          if (yystack_.size () == 1)
            YYABORT;

          yy_destroy_ ("Error: popping", yystack_[0]);
          yypop_ ();
          YY_STACK_PRINT ();
        }


      // Shift the error token.
      error_token.state = yyn;
      yypush_ ("Shifting", YY_MOVE (error_token));
    }
    goto yynewstate;


  /*-------------------------------------.
  | yyacceptlab -- YYACCEPT comes here.  |
  `-------------------------------------*/
  yyacceptlab:
    yyresult = 0;
    goto yyreturn;


  /*-----------------------------------.
  | yyabortlab -- YYABORT comes here.  |
  `-----------------------------------*/
  yyabortlab:
    yyresult = 1;
    goto yyreturn;


  /*-----------------------------------------------------.
  | yyreturn -- parsing is finished, return the result.  |
  `-----------------------------------------------------*/
  yyreturn:
    if (!yyla.empty ())
      yy_destroy_ ("Cleanup: discarding lookahead", yyla);

    /* Do not reclaim the symbols of the rule whose action triggered
       this YYABORT or YYACCEPT.  */
    yypop_ (yylen);
    while (1 < yystack_.size ())
      {
        yy_destroy_ ("Cleanup: popping", yystack_[0]);
        yypop_ ();
      }

    return yyresult;
  }
#if YY_EXCEPTIONS
    catch (...)
      {
        YYCDEBUG << "Exception caught: cleaning lookahead and stack\n";
        // Do not try to display the values of the reclaimed symbols,
        // as their printers might throw an exception.
        if (!yyla.empty ())
          yy_destroy_ (YY_NULLPTR, yyla);

        while (1 < yystack_.size ())
          {
            yy_destroy_ (YY_NULLPTR, yystack_[0]);
            yypop_ ();
          }
        throw;
      }
#endif // YY_EXCEPTIONS
  }

  void
  Parser::error (const syntax_error& yyexc)
  {
    error (yyexc.what ());
  }

  // Generate an error message.
  std::string
  Parser::yysyntax_error_ (state_type, const symbol_type&) const
  {
    return YY_("syntax error");
  }


  const signed char Parser::yypact_ninf_ = -35;

  const signed char Parser::yytable_ninf_ = -1;

  const short
  Parser::yypact_[] =
  {
     -35,    12,    80,   -35,   -35,   -35,   -35,   -35,   -35,   -35,
       4,   -35,   -35,   -14,     5,    49,   -35,     9,   -35,   -35,
      10,    34,     4,   -35,   -35,   -35,    80,   -35,    80,   -35,
      11,    14,    15,    44,     3,   -35,   106,     3,   -35,    47,
      53,    40,    51,   106,   106,   -35,   -35,   -35,   -35,   106,
     -35,    64,   106,   173,   -35,   -35,   -35,   -35,   -35,   193,
      61,   -35,   -35,    74,    82,   106,    86,   111,   132,   153,
     -35,   -35,   -35,   106,   106,   106,   106,   106,   106,   106,
     106,   106,   106,   106,   106,   -35,   -35,   -35,   -35,   243,
     -35,   243,    42,    87,    90,   -35,     7,     7,   -35,   -35,
     269,   256,    81,    98,   282,   295,   308,   321,   -35,   106,
     -35,   -35,   243,    80,    80,   225,   235,   113,   -35,    91,
     -35,    80,   245,   -35
  };

  const unsigned char
  Parser::yydefact_[] =
  {
       4,     0,     2,     1,    57,    56,    58,     3,     5,     6,
       0,    60,    63,     0,    55,     0,     7,     0,    59,     9,
       0,    11,     0,     4,     8,    10,     0,    13,    16,    12,
       0,     0,     0,     0,     0,    14,     0,     0,    15,     0,
       0,     0,    61,     0,     0,    47,    48,    45,    46,     0,
      26,     0,     0,     0,    43,    50,    44,    62,    61,     0,
       0,    17,    27,     0,     0,     0,     0,     0,     0,     0,
      42,    33,    25,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,    21,    20,    18,    19,    28,
      51,    53,     0,     0,     0,    49,    29,    30,    31,    32,
      34,    35,    36,    37,    38,    39,    40,    41,    52,     0,
       4,     4,    54,    16,    16,     0,     0,    22,    24,     0,
       4,    16,     0,    23
  };

  const signed char
  Parser::yypgoto_[] =
  {
     -35,   -35,   -23,   -35,   -35,   -35,   -35,    35,   -35,   -35,
      43,   -35,   -35,   -34,    73,   -24,   -35,   -12,   -35,   -35,
     -26,    -9
  };

  const signed char
  Parser::yydefgoto_[] =
  {
      -1,     1,     2,     7,     8,     9,    17,    20,    21,    24,
      30,    38,    39,    53,    54,    55,    92,    10,    11,    14,
      56,    42
  };

  const signed char
  Parser::yytable_[] =
  {
      28,    13,    59,    22,    41,    15,    40,    16,    57,    67,
      68,    60,     3,    27,    22,    69,    12,    12,    71,    34,
      31,    18,    32,    33,    12,    58,    23,    34,    58,    35,
      25,    89,    91,    43,    44,    36,    37,    75,    76,    96,
      97,    98,    99,   100,   101,   102,   103,   104,   105,   106,
     107,    45,    46,     4,     5,     6,    26,    12,    47,    48,
      34,    29,   108,    49,   109,    50,    63,    64,    61,    19,
      66,    45,    46,    51,    62,   112,    52,    12,    47,    48,
      34,    65,    86,    49,     4,     5,     6,   113,   114,    41,
      41,    40,    40,    45,    46,    87,    41,   121,    40,    12,
      47,    48,    34,    88,   110,    49,    90,   111,   120,    73,
      74,    75,    76,    45,    46,    51,    -1,    80,    52,    12,
      47,    48,    34,   119,    70,    49,    73,    74,    75,    76,
       0,    93,     0,     0,    -1,    51,     0,     0,    52,    73,
      74,    75,    76,     0,    77,    78,    79,    80,    81,    82,
      83,    84,    94,     0,     0,     0,   115,   116,     0,     0,
      73,    74,    75,    76,   122,    77,    78,    79,    80,    81,
      82,    83,    84,    95,     0,     0,     0,     0,     0,     0,
       0,    73,    74,    75,    76,     0,    77,    78,    79,    80,
      81,    82,    83,    84,    72,     0,     0,     0,     0,     0,
       0,    73,    74,    75,    76,     0,    77,    78,    79,    80,
      81,    82,    83,    84,    85,     0,     0,     0,     0,     0,
       0,    73,    74,    75,    76,     0,    77,    78,    79,    80,
      81,    82,    83,    84,    31,     0,    32,    33,    12,     0,
       0,    34,     0,   117,    31,     0,    32,    33,    12,    36,
      37,    34,     0,   118,    31,     0,    32,    33,    12,    36,
      37,    34,     0,   123,     0,     0,     0,     0,     0,    36,
      37,    73,    74,    75,    76,     0,    77,    78,    79,    80,
      81,    82,    83,    84,    73,    74,    75,    76,     0,    77,
       0,    79,    80,    81,    82,    83,    84,    73,    74,    75,
      76,     0,     0,     0,    79,    80,    81,    82,    83,    84,
      73,    74,    75,    76,     0,     0,     0,    79,    80,    -1,
      82,    83,    84,    73,    74,    75,    76,     0,     0,     0,
      79,    80,     0,    -1,    83,    84,    73,    74,    75,    76,
       0,     0,     0,    79,    80,     0,     0,    -1,    84,    73,
      74,    75,    76,     0,     0,     0,    79,    80,     0,     0,
       0,    -1
  };

  const signed char
  Parser::yycheck_[] =
  {
      23,    10,    36,    15,    30,    19,    30,    21,    34,    43,
      44,    37,     0,    22,    26,    49,    13,    13,    52,    16,
       9,    16,    11,    12,    13,    34,    17,    16,    37,    18,
      20,    65,    66,    19,    19,    24,    25,    30,    31,    73,
      74,    75,    76,    77,    78,    79,    80,    81,    82,    83,
      84,     7,     8,     4,     5,     6,    22,    13,    14,    15,
      16,    26,    20,    19,    22,    21,    26,    27,    21,    20,
      19,     7,     8,    29,    21,   109,    32,    13,    14,    15,
      16,    41,    21,    19,     4,     5,     6,   110,   111,   115,
     116,   115,   116,     7,     8,    21,   122,   120,   122,    13,
      14,    15,    16,    21,    17,    19,    20,    17,    17,    28,
      29,    30,    31,     7,     8,    29,    35,    36,    32,    13,
      14,    15,    16,    10,    51,    19,    28,    29,    30,    31,
      -1,    20,    -1,    -1,    36,    29,    -1,    -1,    32,    28,
      29,    30,    31,    -1,    33,    34,    35,    36,    37,    38,
      39,    40,    20,    -1,    -1,    -1,   113,   114,    -1,    -1,
      28,    29,    30,    31,   121,    33,    34,    35,    36,    37,
      38,    39,    40,    20,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    28,    29,    30,    31,    -1,    33,    34,    35,    36,
      37,    38,    39,    40,    21,    -1,    -1,    -1,    -1,    -1,
      -1,    28,    29,    30,    31,    -1,    33,    34,    35,    36,
      37,    38,    39,    40,    21,    -1,    -1,    -1,    -1,    -1,
      -1,    28,    29,    30,    31,    -1,    33,    34,    35,    36,
      37,    38,    39,    40,     9,    -1,    11,    12,    13,    -1,
      -1,    16,    -1,    18,     9,    -1,    11,    12,    13,    24,
      25,    16,    -1,    18,     9,    -1,    11,    12,    13,    24,
      25,    16,    -1,    18,    -1,    -1,    -1,    -1,    -1,    24,
      25,    28,    29,    30,    31,    -1,    33,    34,    35,    36,
      37,    38,    39,    40,    28,    29,    30,    31,    -1,    33,
      -1,    35,    36,    37,    38,    39,    40,    28,    29,    30,
      31,    -1,    -1,    -1,    35,    36,    37,    38,    39,    40,
      28,    29,    30,    31,    -1,    -1,    -1,    35,    36,    37,
      38,    39,    40,    28,    29,    30,    31,    -1,    -1,    -1,
      35,    36,    -1,    38,    39,    40,    28,    29,    30,    31,
      -1,    -1,    -1,    35,    36,    -1,    -1,    39,    40,    28,
      29,    30,    31,    -1,    -1,    -1,    35,    36,    -1,    -1,
      -1,    40
  };

  const unsigned char
  Parser::yystos_[] =
  {
       0,    43,    44,     0,     4,     5,     6,    45,    46,    47,
      59,    60,    13,    63,    61,    19,    21,    48,    16,    20,
      49,    50,    59,    17,    51,    20,    22,    63,    44,    49,
      52,     9,    11,    12,    16,    18,    24,    25,    53,    54,
      57,    62,    63,    19,    19,     7,     8,    14,    15,    19,
      21,    29,    32,    55,    56,    57,    62,    62,    63,    55,
      62,    21,    21,    26,    27,    41,    19,    55,    55,    55,
      56,    55,    21,    28,    29,    30,    31,    33,    34,    35,
      36,    37,    38,    39,    40,    21,    21,    21,    21,    55,
      20,    55,    58,    20,    20,    20,    55,    55,    55,    55,
      55,    55,    55,    55,    55,    55,    55,    55,    20,    22,
      17,    17,    55,    44,    44,    52,    52,    18,    18,    10,
      17,    44,    52,    18
  };

  const unsigned char
  Parser::yyr1_[] =
  {
       0,    42,    43,    44,    44,    45,    45,    46,    47,    48,
      48,    49,    49,    50,    51,    52,    52,    53,    53,    53,
      53,    53,    53,    53,    53,    53,    53,    53,    54,    55,
      55,    55,    55,    55,    55,    55,    55,    55,    55,    55,
      55,    55,    55,    55,    56,    56,    56,    56,    56,    56,
      56,    57,    57,    58,    58,    59,    60,    60,    60,    61,
      61,    62,    62,    63
  };

  const unsigned char
  Parser::yyr2_[] =
  {
       0,     2,     1,     2,     0,     1,     1,     3,     4,     2,
       3,     1,     3,     2,     4,     2,     0,     2,     3,     3,
       3,     3,     8,    13,     8,     3,     2,     2,     3,     3,
       3,     3,     3,     2,     3,     3,     3,     3,     3,     3,
       3,     3,     2,     1,     1,     1,     1,     1,     1,     3,
       1,     3,     4,     1,     3,     2,     1,     1,     1,     2,
       0,     1,     2,     1
  };



  // YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
  // First, the terminals, then, starting at \a yyntokens_, nonterminals.
  const char*
  const Parser::yytname_[] =
  {
  "\"end of file\"", "error", "$undefined", "\"newline\"", "BOOL", "INT",
  "VOID", "TRUE", "FALSE", "IF", "ELSE", "WHILE", "RETURN", "ID",
  "INTLITERAL", "STRINGLITERAL", "DEREF", "LCURLY", "RCURLY", "LPAREN",
  "RPAREN", "SEMICOLON", "COMMA", "DOT", "WRITE", "READ", "CROSSCROSS",
  "DASHDASH", "CROSS", "DASH", "STAR", "SLASH", "NOT", "AND", "OR",
  "EQUALS", "NOTEQUALS", "LESS", "GREATER", "LESSEQ", "GREATEREQ",
  "ASSIGN", "$accept", "program", "declList", "decl", "varDecl", "fnDecl",
  "formals", "formalsList", "formalDecl", "fnBody", "stmtList", "stmt",
  "assignExp", "exp", "term", "fncall", "actualList", "type", "primtype",
  "indirect", "loc", "id", YY_NULLPTR
  };

#if YYDEBUG
  const unsigned short
  Parser::yyrline_[] =
  {
       0,   163,   163,   169,   173,   178,   181,   184,   187,   190,
     193,   196,   200,   204,   207,   210,   214,   217,   220,   223,
     226,   229,   232,   235,   238,   241,   244,   247,   250,   253,
     256,   259,   262,   265,   268,   271,   274,   277,   280,   283,
     286,   289,   292,   295,   298,   301,   304,   307,   310,   313,
     316,   319,   323,   327,   331,   335,   339,   342,   345,   348,
     351,   354,   357,   361
  };

  // Print the state stack on the debug stream.
  void
  Parser::yystack_print_ ()
  {
    *yycdebug_ << "Stack now";
    for (stack_type::const_iterator
           i = yystack_.begin (),
           i_end = yystack_.end ();
         i != i_end; ++i)
      *yycdebug_ << ' ' << i->state;
    *yycdebug_ << '\n';
  }

  // Report on the debug stream that the rule \a yyrule is going to be reduced.
  void
  Parser::yy_reduce_print_ (int yyrule)
  {
    unsigned yylno = yyrline_[yyrule];
    int yynrhs = yyr2_[yyrule];
    // Print the symbols being reduced, and their result.
    *yycdebug_ << "Reducing stack by rule " << yyrule - 1
               << " (line " << yylno << "):\n";
    // The symbols being reduced.
    for (int yyi = 0; yyi < yynrhs; yyi++)
      YY_SYMBOL_PRINT ("   $" << yyi + 1 << " =",
                       yystack_[(yynrhs) - (yyi + 1)]);
  }
#endif // YYDEBUG

  Parser::token_number_type
  Parser::yytranslate_ (int t)
  {
    // YYTRANSLATE[TOKEN-NUM] -- Symbol number corresponding to
    // TOKEN-NUM as returned by yylex.
    static
    const token_number_type
    translate_table[] =
    {
       0,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     1,     2,     3,     4,
       5,     6,     7,     8,     9,    10,    11,    12,    13,    14,
      15,    16,    17,    18,    19,    20,    21,    22,    23,    24,
      25,    26,    27,    28,    29,    30,    31,    32,    33,    34,
      35,    36,    37,    38,    39,    40,    41
    };
    const unsigned user_token_number_max_ = 296;
    const token_number_type undef_token_ = 2;

    if (static_cast<int> (t) <= yyeof_)
      return yyeof_;
    else if (static_cast<unsigned> (t) <= user_token_number_max_)
      return translate_table[t];
    else
      return undef_token_;
  }

#line 5 "lake.yy"
} // lake
#line 1538 "parser.cc"

#line 362 "lake.yy"

void
lake::Parser::error(const std::string &err_message )
{
   std::cerr << "Error: " << err_message << "\n";
}
