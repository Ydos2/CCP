/* A Bison parser, made by GNU Bison 3.8.2.  */

/* Bison implementation for Yacc-like parsers in C

   Copyright (C) 1984, 1989-1990, 2000-2015, 2018-2021 Free Software Foundation,
   Inc.

   This program is free software: you can redistribute it and/or modify
   it under the terms of the GNU General Public License as published by
   the Free Software Foundation, either version 3 of the License, or
   (at your option) any later version.

   This program is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
   GNU General Public License for more details.

   You should have received a copy of the GNU General Public License
   along with this program.  If not, see <https://www.gnu.org/licenses/>.  */

/* As a special exception, you may create a larger work that contains
   part or all of the Bison parser skeleton and distribute that work
   under terms of your choice, so long as that work isn't itself a
   parser generator using the skeleton or a modified version thereof
   as a parser skeleton.  Alternatively, if you modify or redistribute
   the parser skeleton itself, you may (at your option) remove this
   special exception, which will cause the skeleton and the resulting
   Bison output files to be licensed under the GNU General Public
   License without this special exception.

   This special exception was added by the Free Software Foundation in
   version 2.2 of Bison.  */

/* C LALR(1) parser skeleton written by Richard Stallman, by
   simplifying the original so-called "semantic" parser.  */

/* DO NOT RELY ON FEATURES THAT ARE NOT DOCUMENTED in the manual,
   especially those whose name start with YY_ or yy_.  They are
   private implementation details that can be changed or removed.  */

/* All symbols defined below should begin with yy or YY, to avoid
   infringing on user name space.  This should be done even for local
   variables, as they might otherwise be expanded by user macros.
   There are some unavoidable exceptions within include files to
   define necessary library symbols; they are noted "INFRINGES ON
   USER NAME SPACE" below.  */

/* Identify Bison output, and Bison version.  */
#define YYBISON 30802

/* Bison version string.  */
#define YYBISON_VERSION "3.8.2"

/* Skeleton name.  */
#define YYSKELETON_NAME "yacc.c"

/* Pure parsers.  */
#define YYPURE 0

/* Push parsers.  */
#define YYPUSH 0

/* Pull parsers.  */
#define YYPULL 1




/* First part of user prologue.  */
#line 1 "parser.ypp"

    #include <cstdio>
    #include <cstdlib>

    #include "ast.hpp"
    #include "primitive.hpp"
    #include "symtab.hpp"

    #include <iostream>
    using namespace std;

    #define YYDEBUG 1

    extern Program_ptr ast;
    int yylex(void);
    void yyerror(const char *);

#line 89 "parser.cpp"

# ifndef YY_CAST
#  ifdef __cplusplus
#   define YY_CAST(Type, Val) static_cast<Type> (Val)
#   define YY_REINTERPRET_CAST(Type, Val) reinterpret_cast<Type> (Val)
#  else
#   define YY_CAST(Type, Val) ((Type) (Val))
#   define YY_REINTERPRET_CAST(Type, Val) ((Type) (Val))
#  endif
# endif
# ifndef YY_NULLPTR
#  if defined __cplusplus
#   if 201103L <= __cplusplus
#    define YY_NULLPTR nullptr
#   else
#    define YY_NULLPTR 0
#   endif
#  else
#   define YY_NULLPTR ((void*)0)
#  endif
# endif

#include "parser.hpp"
/* Symbol kind.  */
enum yysymbol_kind_t
{
  YYSYMBOL_YYEMPTY = -2,
  YYSYMBOL_YYEOF = 0,                      /* "end of file"  */
  YYSYMBOL_YYerror = 1,                    /* error  */
  YYSYMBOL_YYUNDEF = 2,                    /* "invalid token"  */
  YYSYMBOL_PROCEDURE = 3,                  /* PROCEDURE  */
  YYSYMBOL_VAR = 4,                        /* VAR  */
  YYSYMBOL_RETURN = 5,                     /* RETURN  */
  YYSYMBOL_IF = 6,                         /* IF  */
  YYSYMBOL_ELSE = 7,                       /* ELSE  */
  YYSYMBOL_WHILE = 8,                      /* WHILE  */
  YYSYMBOL__NULL_ = 9,                     /* _NULL_  */
  YYSYMBOL_INTPTR = 10,                    /* INTPTR  */
  YYSYMBOL_CHARPTR = 11,                   /* CHARPTR  */
  YYSYMBOL_AND = 12,                       /* AND  */
  YYSYMBOL_EQUAL = 13,                     /* EQUAL  */
  YYSYMBOL_EQUALMORE = 14,                 /* EQUALMORE  */
  YYSYMBOL_EQUALLESS = 15,                 /* EQUALLESS  */
  YYSYMBOL_DIFF = 16,                      /* DIFF  */
  YYSYMBOL_OR = 17,                        /* OR  */
  YYSYMBOL_BOOLEAN = 18,                   /* BOOLEAN  */
  YYSYMBOL_INTEGER = 19,                   /* INTEGER  */
  YYSYMBOL_CHAR = 20,                      /* CHAR  */
  YYSYMBOL_STRING = 21,                    /* STRING  */
  YYSYMBOL_WORD = 22,                      /* WORD  */
  YYSYMBOL_23_ = 23,                       /* '='  */
  YYSYMBOL_24_ = 24,                       /* '^'  */
  YYSYMBOL_25_ = 25,                       /* '&'  */
  YYSYMBOL_26_ = 26,                       /* '!'  */
  YYSYMBOL_27_ = 27,                       /* '>'  */
  YYSYMBOL_28_ = 28,                       /* '<'  */
  YYSYMBOL_29_ = 29,                       /* '+'  */
  YYSYMBOL_30_ = 30,                       /* '-'  */
  YYSYMBOL_31_ = 31,                       /* '*'  */
  YYSYMBOL_32_ = 32,                       /* '/'  */
  YYSYMBOL_33_ = 33,                       /* '('  */
  YYSYMBOL_34_ = 34,                       /* ')'  */
  YYSYMBOL_35_ = 35,                       /* '{'  */
  YYSYMBOL_36_ = 36,                       /* '}'  */
  YYSYMBOL_37_ = 37,                       /* ':'  */
  YYSYMBOL_38_ = 38,                       /* ';'  */
  YYSYMBOL_39_ = 39,                       /* ','  */
  YYSYMBOL_40_ = 40,                       /* '['  */
  YYSYMBOL_41_ = 41,                       /* ']'  */
  YYSYMBOL_42_ = 42,                       /* '|'  */
  YYSYMBOL_YYACCEPT = 43,                  /* $accept  */
  YYSYMBOL_start = 44,                     /* start  */
  YYSYMBOL_header_list = 45,               /* header_list  */
  YYSYMBOL_header = 46,                    /* header  */
  YYSYMBOL_func_param = 47,                /* func_param  */
  YYSYMBOL_list_func_param = 48,           /* list_func_param  */
  YYSYMBOL_func_body = 49,                 /* func_body  */
  YYSYMBOL_checks_list = 50,               /* checks_list  */
  YYSYMBOL_checks_header = 51,             /* checks_header  */
  YYSYMBOL_checks = 52,                    /* checks  */
  YYSYMBOL_nested_list = 53,               /* nested_list  */
  YYSYMBOL_expression_list = 54,           /* expression_list  */
  YYSYMBOL_expression = 55,                /* expression  */
  YYSYMBOL_expression_check = 56,          /* expression_check  */
  YYSYMBOL_get_var = 57,                   /* get_var  */
  YYSYMBOL_keywords = 58,                  /* keywords  */
  YYSYMBOL_types = 59,                     /* types  */
  YYSYMBOL_operator = 60,                  /* operator  */
  YYSYMBOL_paranthesis = 61                /* paranthesis  */
};
typedef enum yysymbol_kind_t yysymbol_kind_t;




#ifdef short
# undef short
#endif

/* On compilers that do not define __PTRDIFF_MAX__ etc., make sure
   <limits.h> and (if available) <stdint.h> are included
   so that the code can choose integer types of a good width.  */

#ifndef __PTRDIFF_MAX__
# include <limits.h> /* INFRINGES ON USER NAME SPACE */
# if defined __STDC_VERSION__ && 199901 <= __STDC_VERSION__
#  include <stdint.h> /* INFRINGES ON USER NAME SPACE */
#  define YY_STDINT_H
# endif
#endif

/* Narrow types that promote to a signed type and that can represent a
   signed or unsigned integer of at least N bits.  In tables they can
   save space and decrease cache pressure.  Promoting to a signed type
   helps avoid bugs in integer arithmetic.  */

#ifdef __INT_LEAST8_MAX__
typedef __INT_LEAST8_TYPE__ yytype_int8;
#elif defined YY_STDINT_H
typedef int_least8_t yytype_int8;
#else
typedef signed char yytype_int8;
#endif

#ifdef __INT_LEAST16_MAX__
typedef __INT_LEAST16_TYPE__ yytype_int16;
#elif defined YY_STDINT_H
typedef int_least16_t yytype_int16;
#else
typedef short yytype_int16;
#endif

/* Work around bug in HP-UX 11.23, which defines these macros
   incorrectly for preprocessor constants.  This workaround can likely
   be removed in 2023, as HPE has promised support for HP-UX 11.23
   (aka HP-UX 11i v2) only through the end of 2022; see Table 2 of
   <https://h20195.www2.hpe.com/V2/getpdf.aspx/4AA4-7673ENW.pdf>.  */
#ifdef __hpux
# undef UINT_LEAST8_MAX
# undef UINT_LEAST16_MAX
# define UINT_LEAST8_MAX 255
# define UINT_LEAST16_MAX 65535
#endif

#if defined __UINT_LEAST8_MAX__ && __UINT_LEAST8_MAX__ <= __INT_MAX__
typedef __UINT_LEAST8_TYPE__ yytype_uint8;
#elif (!defined __UINT_LEAST8_MAX__ && defined YY_STDINT_H \
       && UINT_LEAST8_MAX <= INT_MAX)
typedef uint_least8_t yytype_uint8;
#elif !defined __UINT_LEAST8_MAX__ && UCHAR_MAX <= INT_MAX
typedef unsigned char yytype_uint8;
#else
typedef short yytype_uint8;
#endif

#if defined __UINT_LEAST16_MAX__ && __UINT_LEAST16_MAX__ <= __INT_MAX__
typedef __UINT_LEAST16_TYPE__ yytype_uint16;
#elif (!defined __UINT_LEAST16_MAX__ && defined YY_STDINT_H \
       && UINT_LEAST16_MAX <= INT_MAX)
typedef uint_least16_t yytype_uint16;
#elif !defined __UINT_LEAST16_MAX__ && USHRT_MAX <= INT_MAX
typedef unsigned short yytype_uint16;
#else
typedef int yytype_uint16;
#endif

#ifndef YYPTRDIFF_T
# if defined __PTRDIFF_TYPE__ && defined __PTRDIFF_MAX__
#  define YYPTRDIFF_T __PTRDIFF_TYPE__
#  define YYPTRDIFF_MAXIMUM __PTRDIFF_MAX__
# elif defined PTRDIFF_MAX
#  ifndef ptrdiff_t
#   include <stddef.h> /* INFRINGES ON USER NAME SPACE */
#  endif
#  define YYPTRDIFF_T ptrdiff_t
#  define YYPTRDIFF_MAXIMUM PTRDIFF_MAX
# else
#  define YYPTRDIFF_T long
#  define YYPTRDIFF_MAXIMUM LONG_MAX
# endif
#endif

#ifndef YYSIZE_T
# ifdef __SIZE_TYPE__
#  define YYSIZE_T __SIZE_TYPE__
# elif defined size_t
#  define YYSIZE_T size_t
# elif defined __STDC_VERSION__ && 199901 <= __STDC_VERSION__
#  include <stddef.h> /* INFRINGES ON USER NAME SPACE */
#  define YYSIZE_T size_t
# else
#  define YYSIZE_T unsigned
# endif
#endif

#define YYSIZE_MAXIMUM                                  \
  YY_CAST (YYPTRDIFF_T,                                 \
           (YYPTRDIFF_MAXIMUM < YY_CAST (YYSIZE_T, -1)  \
            ? YYPTRDIFF_MAXIMUM                         \
            : YY_CAST (YYSIZE_T, -1)))

#define YYSIZEOF(X) YY_CAST (YYPTRDIFF_T, sizeof (X))


/* Stored state numbers (used for stacks). */
typedef yytype_uint8 yy_state_t;

/* State numbers in computations.  */
typedef int yy_state_fast_t;

#ifndef YY_
# if defined YYENABLE_NLS && YYENABLE_NLS
#  if ENABLE_NLS
#   include <libintl.h> /* INFRINGES ON USER NAME SPACE */
#   define YY_(Msgid) dgettext ("bison-runtime", Msgid)
#  endif
# endif
# ifndef YY_
#  define YY_(Msgid) Msgid
# endif
#endif


#ifndef YY_ATTRIBUTE_PURE
# if defined __GNUC__ && 2 < __GNUC__ + (96 <= __GNUC_MINOR__)
#  define YY_ATTRIBUTE_PURE __attribute__ ((__pure__))
# else
#  define YY_ATTRIBUTE_PURE
# endif
#endif

#ifndef YY_ATTRIBUTE_UNUSED
# if defined __GNUC__ && 2 < __GNUC__ + (7 <= __GNUC_MINOR__)
#  define YY_ATTRIBUTE_UNUSED __attribute__ ((__unused__))
# else
#  define YY_ATTRIBUTE_UNUSED
# endif
#endif

/* Suppress unused-variable warnings by "using" E.  */
#if ! defined lint || defined __GNUC__
# define YY_USE(E) ((void) (E))
#else
# define YY_USE(E) /* empty */
#endif

/* Suppress an incorrect diagnostic about yylval being uninitialized.  */
#if defined __GNUC__ && ! defined __ICC && 406 <= __GNUC__ * 100 + __GNUC_MINOR__
# if __GNUC__ * 100 + __GNUC_MINOR__ < 407
#  define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN                           \
    _Pragma ("GCC diagnostic push")                                     \
    _Pragma ("GCC diagnostic ignored \"-Wuninitialized\"")
# else
#  define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN                           \
    _Pragma ("GCC diagnostic push")                                     \
    _Pragma ("GCC diagnostic ignored \"-Wuninitialized\"")              \
    _Pragma ("GCC diagnostic ignored \"-Wmaybe-uninitialized\"")
# endif
# define YY_IGNORE_MAYBE_UNINITIALIZED_END      \
    _Pragma ("GCC diagnostic pop")
#else
# define YY_INITIAL_VALUE(Value) Value
#endif
#ifndef YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
# define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
# define YY_IGNORE_MAYBE_UNINITIALIZED_END
#endif
#ifndef YY_INITIAL_VALUE
# define YY_INITIAL_VALUE(Value) /* Nothing. */
#endif

#if defined __cplusplus && defined __GNUC__ && ! defined __ICC && 6 <= __GNUC__
# define YY_IGNORE_USELESS_CAST_BEGIN                          \
    _Pragma ("GCC diagnostic push")                            \
    _Pragma ("GCC diagnostic ignored \"-Wuseless-cast\"")
# define YY_IGNORE_USELESS_CAST_END            \
    _Pragma ("GCC diagnostic pop")
#endif
#ifndef YY_IGNORE_USELESS_CAST_BEGIN
# define YY_IGNORE_USELESS_CAST_BEGIN
# define YY_IGNORE_USELESS_CAST_END
#endif


#define YY_ASSERT(E) ((void) (0 && (E)))

#if 1

/* The parser invokes alloca or malloc; define the necessary symbols.  */

# ifdef YYSTACK_USE_ALLOCA
#  if YYSTACK_USE_ALLOCA
#   ifdef __GNUC__
#    define YYSTACK_ALLOC __builtin_alloca
#   elif defined __BUILTIN_VA_ARG_INCR
#    include <alloca.h> /* INFRINGES ON USER NAME SPACE */
#   elif defined _AIX
#    define YYSTACK_ALLOC __alloca
#   elif defined _MSC_VER
#    include <malloc.h> /* INFRINGES ON USER NAME SPACE */
#    define alloca _alloca
#   else
#    define YYSTACK_ALLOC alloca
#    if ! defined _ALLOCA_H && ! defined EXIT_SUCCESS
#     include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
      /* Use EXIT_SUCCESS as a witness for stdlib.h.  */
#     ifndef EXIT_SUCCESS
#      define EXIT_SUCCESS 0
#     endif
#    endif
#   endif
#  endif
# endif

# ifdef YYSTACK_ALLOC
   /* Pacify GCC's 'empty if-body' warning.  */
#  define YYSTACK_FREE(Ptr) do { /* empty */; } while (0)
#  ifndef YYSTACK_ALLOC_MAXIMUM
    /* The OS might guarantee only one guard page at the bottom of the stack,
       and a page size can be as small as 4096 bytes.  So we cannot safely
       invoke alloca (N) if N exceeds 4096.  Use a slightly smaller number
       to allow for a few compiler-allocated temporary stack slots.  */
#   define YYSTACK_ALLOC_MAXIMUM 4032 /* reasonable circa 2006 */
#  endif
# else
#  define YYSTACK_ALLOC YYMALLOC
#  define YYSTACK_FREE YYFREE
#  ifndef YYSTACK_ALLOC_MAXIMUM
#   define YYSTACK_ALLOC_MAXIMUM YYSIZE_MAXIMUM
#  endif
#  if (defined __cplusplus && ! defined EXIT_SUCCESS \
       && ! ((defined YYMALLOC || defined malloc) \
             && (defined YYFREE || defined free)))
#   include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
#   ifndef EXIT_SUCCESS
#    define EXIT_SUCCESS 0
#   endif
#  endif
#  ifndef YYMALLOC
#   define YYMALLOC malloc
#   if ! defined malloc && ! defined EXIT_SUCCESS
void *malloc (YYSIZE_T); /* INFRINGES ON USER NAME SPACE */
#   endif
#  endif
#  ifndef YYFREE
#   define YYFREE free
#   if ! defined free && ! defined EXIT_SUCCESS
void free (void *); /* INFRINGES ON USER NAME SPACE */
#   endif
#  endif
# endif
#endif /* 1 */

#if (! defined yyoverflow \
     && (! defined __cplusplus \
         || (defined YYSTYPE_IS_TRIVIAL && YYSTYPE_IS_TRIVIAL)))

/* A type that is properly aligned for any stack member.  */
union yyalloc
{
  yy_state_t yyss_alloc;
  YYSTYPE yyvs_alloc;
};

/* The size of the maximum gap between one aligned stack and the next.  */
# define YYSTACK_GAP_MAXIMUM (YYSIZEOF (union yyalloc) - 1)

/* The size of an array large to enough to hold all stacks, each with
   N elements.  */
# define YYSTACK_BYTES(N) \
     ((N) * (YYSIZEOF (yy_state_t) + YYSIZEOF (YYSTYPE)) \
      + YYSTACK_GAP_MAXIMUM)

# define YYCOPY_NEEDED 1

/* Relocate STACK from its old location to the new one.  The
   local variables YYSIZE and YYSTACKSIZE give the old and new number of
   elements in the stack, and YYPTR gives the new location of the
   stack.  Advance YYPTR to a properly aligned location for the next
   stack.  */
# define YYSTACK_RELOCATE(Stack_alloc, Stack)                           \
    do                                                                  \
      {                                                                 \
        YYPTRDIFF_T yynewbytes;                                         \
        YYCOPY (&yyptr->Stack_alloc, Stack, yysize);                    \
        Stack = &yyptr->Stack_alloc;                                    \
        yynewbytes = yystacksize * YYSIZEOF (*Stack) + YYSTACK_GAP_MAXIMUM; \
        yyptr += yynewbytes / YYSIZEOF (*yyptr);                        \
      }                                                                 \
    while (0)

#endif

#if defined YYCOPY_NEEDED && YYCOPY_NEEDED
/* Copy COUNT objects from SRC to DST.  The source and destination do
   not overlap.  */
# ifndef YYCOPY
#  if defined __GNUC__ && 1 < __GNUC__
#   define YYCOPY(Dst, Src, Count) \
      __builtin_memcpy (Dst, Src, YY_CAST (YYSIZE_T, (Count)) * sizeof (*(Src)))
#  else
#   define YYCOPY(Dst, Src, Count)              \
      do                                        \
        {                                       \
          YYPTRDIFF_T yyi;                      \
          for (yyi = 0; yyi < (Count); yyi++)   \
            (Dst)[yyi] = (Src)[yyi];            \
        }                                       \
      while (0)
#  endif
# endif
#endif /* !YYCOPY_NEEDED */

/* YYFINAL -- State number of the termination state.  */
#define YYFINAL  6
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   346

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  43
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  19
/* YYNRULES -- Number of rules.  */
#define YYNRULES  69
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  149

/* YYMAXUTOK -- Last valid token kind.  */
#define YYMAXUTOK   277


/* YYTRANSLATE(TOKEN-NUM) -- Symbol number corresponding to TOKEN-NUM
   as returned by yylex, with out-of-bounds checking.  */
#define YYTRANSLATE(YYX)                                \
  (0 <= (YYX) && (YYX) <= YYMAXUTOK                     \
   ? YY_CAST (yysymbol_kind_t, yytranslate[YYX])        \
   : YYSYMBOL_YYUNDEF)

/* YYTRANSLATE[TOKEN-NUM] -- Symbol number corresponding to TOKEN-NUM
   as returned by yylex.  */
static const yytype_int8 yytranslate[] =
{
       0,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,    26,     2,     2,     2,     2,    25,     2,
      33,    34,    31,    29,    39,    30,     2,    32,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,    37,    38,
      28,    23,    27,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,    40,     2,    41,    24,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,    35,    42,    36,     2,     2,     2,     2,
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
      15,    16,    17,    18,    19,    20,    21,    22
};

#if YYDEBUG
/* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_uint8 yyrline[] =
{
       0,    57,    57,    61,    65,    71,    76,    77,    81,    89,
      93,   101,   104,   108,   109,   115,   116,   124,   125,   126,
     127,   128,   129,   133,   138,   139,   143,   144,   145,   146,
     147,   148,   149,   150,   151,   152,   153,   154,   155,   156,
     160,   161,   162,   166,   167,   171,   178,   179,   180,   184,
     185,   186,   187,   188,   189,   193,   194,   195,   196,   197,
     198,   199,   200,   201,   202,   203,   204,   205,   209,   210
};
#endif

/** Accessing symbol of state STATE.  */
#define YY_ACCESSING_SYMBOL(State) YY_CAST (yysymbol_kind_t, yystos[State])

#if 1
/* The user-facing name of the symbol whose (internal) number is
   YYSYMBOL.  No bounds checking.  */
static const char *yysymbol_name (yysymbol_kind_t yysymbol) YY_ATTRIBUTE_UNUSED;

/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "\"end of file\"", "error", "\"invalid token\"", "PROCEDURE", "VAR",
  "RETURN", "IF", "ELSE", "WHILE", "_NULL_", "INTPTR", "CHARPTR", "AND",
  "EQUAL", "EQUALMORE", "EQUALLESS", "DIFF", "OR", "BOOLEAN", "INTEGER",
  "CHAR", "STRING", "WORD", "'='", "'^'", "'&'", "'!'", "'>'", "'<'",
  "'+'", "'-'", "'*'", "'/'", "'('", "')'", "'{'", "'}'", "':'", "';'",
  "','", "'['", "']'", "'|'", "$accept", "start", "header_list", "header",
  "func_param", "list_func_param", "func_body", "checks_list",
  "checks_header", "checks", "nested_list", "expression_list",
  "expression", "expression_check", "get_var", "keywords", "types",
  "operator", "paranthesis", YY_NULLPTR
};

static const char *
yysymbol_name (yysymbol_kind_t yysymbol)
{
  return yytname[yysymbol];
}
#endif

#define YYPACT_NINF (-126)

#define yypact_value_is_default(Yyn) \
  ((Yyn) == YYPACT_NINF)

#define YYTABLE_NINF (-25)

#define yytable_value_is_error(Yyn) \
  0

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
static const yytype_int16 yypact[] =
{
       2,     6,    41,     2,  -126,    25,  -126,  -126,    52,  -126,
      -5,    30,    73,    52,   200,    55,   200,    45,  -126,  -126,
    -126,  -126,  -126,  -126,  -126,  -126,    48,   200,    53,  -126,
      59,     2,  -126,  -126,    99,    52,    51,    62,    91,    79,
      85,   -30,    97,  -126,  -126,   100,  -126,   227,  -126,  -126,
    -126,  -126,    80,    91,    82,    91,    91,    91,    91,   185,
    -126,  -126,    91,    91,    46,    91,  -126,    86,    99,    72,
      92,    93,    91,   314,    94,  -126,     8,    76,   239,   113,
      91,    91,    91,    91,    91,    91,    91,    91,    91,    91,
      91,    91,    91,  -126,   262,   285,   -25,   308,   134,  -126,
     168,   101,   -27,   212,   116,  -126,   155,  -126,  -126,   314,
       8,    31,    31,     8,   314,   308,    31,    31,    76,    76,
    -126,  -126,   102,   103,   114,    91,  -126,  -126,    46,  -126,
     112,  -126,  -126,  -126,  -126,   308,   -23,   118,   122,   123,
     135,  -126,   147,  -126,  -126,   125,  -126,   141,  -126
};

/* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
   Performed when YYTABLE does not specify something else to do.  Zero
   means the default is an error.  */
static const yytype_int8 yydefact[] =
{
       0,     0,     0,     2,     4,     0,     1,     3,     6,    10,
       0,     0,     0,     0,     0,     0,     0,     0,    53,    54,
      51,    50,    52,    49,     7,     9,     0,     0,    15,     8,
       0,    43,     5,    16,    13,     0,     0,     0,    27,     0,
       0,    40,     0,    43,    14,     0,    21,     0,    39,    37,
      38,    36,    35,    27,     0,    27,    27,    27,    27,     0,
      33,    32,    27,    27,    27,    27,    42,     0,    13,    27,
      49,     0,    27,    29,    40,    31,    30,    28,     0,     0,
      27,    27,    27,    27,    27,    27,    27,    27,    27,    27,
      27,    27,    27,    11,     0,     0,     0,    25,     0,    22,
      23,     0,    35,     0,     0,    44,     0,    69,    68,    55,
      58,    60,    62,    63,    64,    57,    59,    61,    66,    65,
      67,    56,     0,     0,     0,    27,    41,    18,    27,    17,
       0,    34,    43,    43,    20,    26,     0,     0,     0,     0,
       0,    45,    46,    48,    19,     0,    43,     0,    47
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -126,  -126,  -126,    -1,  -126,    -9,  -126,   111,  -126,  -126,
    -125,    60,   -38,   126,   150,  -126,   -15,  -126,  -126
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int8 yydefgoto[] =
{
       0,     2,     3,     4,    10,    11,    30,    36,    31,    44,
      67,    96,    97,    45,    68,    46,    24,    60,    61
};

/* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule whose
   number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int16 yytable[] =
{
      59,    26,     7,    64,    17,     1,   128,   138,   139,   124,
      65,   140,    29,    72,   125,    73,   125,    76,    77,    78,
      79,   147,    82,    83,    94,    95,    37,    98,     5,    12,
      33,   103,    71,    13,   106,    87,    88,    89,    90,    91,
      92,     6,   109,   110,   111,   112,   113,   114,   115,   116,
     117,   118,   119,   120,   121,    48,    38,    39,     8,    40,
      89,    90,    91,    92,    49,    50,    51,    14,    52,    15,
      53,    54,    55,    41,     9,    42,    56,    25,    16,    57,
     -24,    48,    27,    28,    15,   -24,    43,   135,    58,   -12,
      49,    50,    51,   101,   102,    32,    53,    54,    55,    47,
      48,    15,    56,    35,    74,    57,    42,    91,    92,    49,
      50,    51,    62,    52,    58,    53,    54,    55,    63,    66,
      72,    56,    99,    69,    57,    80,    81,    82,    83,    84,
      85,   105,   104,    58,    65,   130,    86,   132,   133,   127,
      87,    88,    89,    90,    91,    92,    80,    81,    82,    83,
      84,    85,   134,   137,   145,   108,   141,    86,   142,   143,
     146,    87,    88,    89,    90,    91,    92,    80,    81,    82,
      83,    84,    85,   144,    39,   126,    40,   148,    86,   100,
      75,    34,    87,    88,    89,    90,    91,    92,   136,     0,
      41,     0,    42,     0,     0,     0,   131,    80,    81,    82,
      83,    84,    85,    43,     0,     0,     0,     0,    86,     0,
      18,    19,    87,    88,    89,    90,    91,    92,    20,    21,
      22,    23,     0,    93,    80,    81,    82,    83,    84,    85,
       0,     0,     0,     0,     0,    86,     0,    18,    19,    87,
      88,    89,    90,    91,    92,    20,    21,    22,    70,     0,
     129,    80,    81,    82,    83,    84,    85,     0,     0,     0,
       0,     0,    86,     0,     0,     0,    87,    88,    89,    90,
      91,    92,     0,   107,    80,    81,    82,    83,    84,    85,
       0,     0,     0,     0,     0,    86,     0,     0,     0,    87,
      88,    89,    90,    91,    92,     0,   122,    80,    81,    82,
      83,    84,    85,     0,     0,     0,     0,     0,    86,     0,
       0,     0,    87,    88,    89,    90,    91,    92,     0,   123,
      80,    81,    82,    83,    84,    85,     0,    81,    82,    83,
      84,    86,     0,     0,     0,    87,    88,    89,    90,    91,
      92,    87,    88,    89,    90,    91,    92
};

static const yytype_int16 yycheck[] =
{
      38,    16,     3,    33,    13,     3,    33,   132,   133,    34,
      40,    34,    27,    40,    39,    53,    39,    55,    56,    57,
      58,   146,    14,    15,    62,    63,    35,    65,    22,    34,
      31,    69,    47,    38,    72,    27,    28,    29,    30,    31,
      32,     0,    80,    81,    82,    83,    84,    85,    86,    87,
      88,    89,    90,    91,    92,     9,     5,     6,    33,     8,
      29,    30,    31,    32,    18,    19,    20,    37,    22,    39,
      24,    25,    26,    22,    22,    24,    30,    22,     5,    33,
      34,     9,    37,    35,    39,    39,    35,   125,    42,    36,
      18,    19,    20,    21,    22,    36,    24,    25,    26,    37,
       9,    39,    30,     4,    22,    33,    24,    31,    32,    18,
      19,    20,    33,    22,    42,    24,    25,    26,    33,    22,
      40,    30,    36,    23,    33,    12,    13,    14,    15,    16,
      17,    38,    40,    42,    40,    19,    23,    35,    35,    38,
      27,    28,    29,    30,    31,    32,    12,    13,    14,    15,
      16,    17,    38,    41,     7,    42,    38,    23,    36,    36,
      35,    27,    28,    29,    30,    31,    32,    12,    13,    14,
      15,    16,    17,    38,     6,    41,     8,    36,    23,    68,
      54,    31,    27,    28,    29,    30,    31,    32,   128,    -1,
      22,    -1,    24,    -1,    -1,    -1,    41,    12,    13,    14,
      15,    16,    17,    35,    -1,    -1,    -1,    -1,    23,    -1,
      10,    11,    27,    28,    29,    30,    31,    32,    18,    19,
      20,    21,    -1,    38,    12,    13,    14,    15,    16,    17,
      -1,    -1,    -1,    -1,    -1,    23,    -1,    10,    11,    27,
      28,    29,    30,    31,    32,    18,    19,    20,    21,    -1,
      38,    12,    13,    14,    15,    16,    17,    -1,    -1,    -1,
      -1,    -1,    23,    -1,    -1,    -1,    27,    28,    29,    30,
      31,    32,    -1,    34,    12,    13,    14,    15,    16,    17,
      -1,    -1,    -1,    -1,    -1,    23,    -1,    -1,    -1,    27,
      28,    29,    30,    31,    32,    -1,    34,    12,    13,    14,
      15,    16,    17,    -1,    -1,    -1,    -1,    -1,    23,    -1,
      -1,    -1,    27,    28,    29,    30,    31,    32,    -1,    34,
      12,    13,    14,    15,    16,    17,    -1,    13,    14,    15,
      16,    23,    -1,    -1,    -1,    27,    28,    29,    30,    31,
      32,    27,    28,    29,    30,    31,    32
};

/* YYSTOS[STATE-NUM] -- The symbol kind of the accessing symbol of
   state STATE-NUM.  */
static const yytype_int8 yystos[] =
{
       0,     3,    44,    45,    46,    22,     0,    46,    33,    22,
      47,    48,    34,    38,    37,    39,     5,    48,    10,    11,
      18,    19,    20,    21,    59,    22,    59,    37,    35,    59,
      49,    51,    36,    46,    57,     4,    50,    48,     5,     6,
       8,    22,    24,    35,    52,    56,    58,    37,     9,    18,
      19,    20,    22,    24,    25,    26,    30,    33,    42,    55,
      60,    61,    33,    33,    33,    40,    22,    53,    57,    23,
      21,    59,    40,    55,    22,    56,    55,    55,    55,    55,
      12,    13,    14,    15,    16,    17,    23,    27,    28,    29,
      30,    31,    32,    38,    55,    55,    54,    55,    55,    36,
      50,    21,    22,    55,    40,    38,    55,    34,    42,    55,
      55,    55,    55,    55,    55,    55,    55,    55,    55,    55,
      55,    55,    34,    34,    34,    39,    41,    38,    33,    38,
      19,    41,    35,    35,    38,    55,    54,    41,    53,    53,
      34,    38,    36,    36,    38,     7,    35,    53,    36
};

/* YYR1[RULE-NUM] -- Symbol kind of the left-hand side of rule RULE-NUM.  */
static const yytype_int8 yyr1[] =
{
       0,    43,    44,    45,    45,    46,    47,    47,    47,    48,
      48,    49,    49,    50,    50,    51,    51,    52,    52,    52,
      52,    52,    52,    53,    54,    54,    54,    55,    55,    55,
      55,    55,    55,    55,    55,    55,    55,    55,    55,    55,
      56,    56,    56,    57,    57,    57,    58,    58,    58,    59,
      59,    59,    59,    59,    59,    60,    60,    60,    60,    60,
      60,    60,    60,    60,    60,    60,    60,    60,    61,    61
};

/* YYR2[RULE-NUM] -- Number of symbols on the right-hand side of rule RULE-NUM.  */
static const yytype_int8 yyr2[] =
{
       0,     2,     1,     2,     1,    10,     0,     3,     5,     3,
       1,     6,     0,     0,     2,     0,     2,     4,     4,     7,
       5,     1,     3,     2,     0,     1,     3,     0,     2,     2,
       2,     2,     1,     1,     4,     1,     1,     1,     1,     1,
       1,     4,     2,     0,     6,     9,     7,    11,     7,     1,
       1,     1,     1,     1,     1,     3,     3,     3,     3,     3,
       3,     3,     3,     3,     3,     3,     3,     3,     3,     3
};


enum { YYENOMEM = -2 };

#define yyerrok         (yyerrstatus = 0)
#define yyclearin       (yychar = YYEMPTY)

#define YYACCEPT        goto yyacceptlab
#define YYABORT         goto yyabortlab
#define YYERROR         goto yyerrorlab
#define YYNOMEM         goto yyexhaustedlab


#define YYRECOVERING()  (!!yyerrstatus)

#define YYBACKUP(Token, Value)                                    \
  do                                                              \
    if (yychar == YYEMPTY)                                        \
      {                                                           \
        yychar = (Token);                                         \
        yylval = (Value);                                         \
        YYPOPSTACK (yylen);                                       \
        yystate = *yyssp;                                         \
        goto yybackup;                                            \
      }                                                           \
    else                                                          \
      {                                                           \
        yyerror (YY_("syntax error: cannot back up")); \
        YYERROR;                                                  \
      }                                                           \
  while (0)

/* Backward compatibility with an undocumented macro.
   Use YYerror or YYUNDEF. */
#define YYERRCODE YYUNDEF


/* Enable debugging if requested.  */
#if YYDEBUG

# ifndef YYFPRINTF
#  include <stdio.h> /* INFRINGES ON USER NAME SPACE */
#  define YYFPRINTF fprintf
# endif

# define YYDPRINTF(Args)                        \
do {                                            \
  if (yydebug)                                  \
    YYFPRINTF Args;                             \
} while (0)




# define YY_SYMBOL_PRINT(Title, Kind, Value, Location)                    \
do {                                                                      \
  if (yydebug)                                                            \
    {                                                                     \
      YYFPRINTF (stderr, "%s ", Title);                                   \
      yy_symbol_print (stderr,                                            \
                  Kind, Value); \
      YYFPRINTF (stderr, "\n");                                           \
    }                                                                     \
} while (0)


/*-----------------------------------.
| Print this symbol's value on YYO.  |
`-----------------------------------*/

static void
yy_symbol_value_print (FILE *yyo,
                       yysymbol_kind_t yykind, YYSTYPE const * const yyvaluep)
{
  FILE *yyoutput = yyo;
  YY_USE (yyoutput);
  if (!yyvaluep)
    return;
  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  YY_USE (yykind);
  YY_IGNORE_MAYBE_UNINITIALIZED_END
}


/*---------------------------.
| Print this symbol on YYO.  |
`---------------------------*/

static void
yy_symbol_print (FILE *yyo,
                 yysymbol_kind_t yykind, YYSTYPE const * const yyvaluep)
{
  YYFPRINTF (yyo, "%s %s (",
             yykind < YYNTOKENS ? "token" : "nterm", yysymbol_name (yykind));

  yy_symbol_value_print (yyo, yykind, yyvaluep);
  YYFPRINTF (yyo, ")");
}

/*------------------------------------------------------------------.
| yy_stack_print -- Print the state stack from its BOTTOM up to its |
| TOP (included).                                                   |
`------------------------------------------------------------------*/

static void
yy_stack_print (yy_state_t *yybottom, yy_state_t *yytop)
{
  YYFPRINTF (stderr, "Stack now");
  for (; yybottom <= yytop; yybottom++)
    {
      int yybot = *yybottom;
      YYFPRINTF (stderr, " %d", yybot);
    }
  YYFPRINTF (stderr, "\n");
}

# define YY_STACK_PRINT(Bottom, Top)                            \
do {                                                            \
  if (yydebug)                                                  \
    yy_stack_print ((Bottom), (Top));                           \
} while (0)


/*------------------------------------------------.
| Report that the YYRULE is going to be reduced.  |
`------------------------------------------------*/

static void
yy_reduce_print (yy_state_t *yyssp, YYSTYPE *yyvsp,
                 int yyrule)
{
  int yylno = yyrline[yyrule];
  int yynrhs = yyr2[yyrule];
  int yyi;
  YYFPRINTF (stderr, "Reducing stack by rule %d (line %d):\n",
             yyrule - 1, yylno);
  /* The symbols being reduced.  */
  for (yyi = 0; yyi < yynrhs; yyi++)
    {
      YYFPRINTF (stderr, "   $%d = ", yyi + 1);
      yy_symbol_print (stderr,
                       YY_ACCESSING_SYMBOL (+yyssp[yyi + 1 - yynrhs]),
                       &yyvsp[(yyi + 1) - (yynrhs)]);
      YYFPRINTF (stderr, "\n");
    }
}

# define YY_REDUCE_PRINT(Rule)          \
do {                                    \
  if (yydebug)                          \
    yy_reduce_print (yyssp, yyvsp, Rule); \
} while (0)

/* Nonzero means print parse trace.  It is left uninitialized so that
   multiple parsers can coexist.  */
int yydebug;
#else /* !YYDEBUG */
# define YYDPRINTF(Args) ((void) 0)
# define YY_SYMBOL_PRINT(Title, Kind, Value, Location)
# define YY_STACK_PRINT(Bottom, Top)
# define YY_REDUCE_PRINT(Rule)
#endif /* !YYDEBUG */


/* YYINITDEPTH -- initial size of the parser's stacks.  */
#ifndef YYINITDEPTH
# define YYINITDEPTH 200
#endif

/* YYMAXDEPTH -- maximum size the stacks can grow to (effective only
   if the built-in stack extension method is used).

   Do not make this value too large; the results are undefined if
   YYSTACK_ALLOC_MAXIMUM < YYSTACK_BYTES (YYMAXDEPTH)
   evaluated with infinite-precision integer arithmetic.  */

#ifndef YYMAXDEPTH
# define YYMAXDEPTH 10000
#endif


/* Context of a parse error.  */
typedef struct
{
  yy_state_t *yyssp;
  yysymbol_kind_t yytoken;
} yypcontext_t;

/* Put in YYARG at most YYARGN of the expected tokens given the
   current YYCTX, and return the number of tokens stored in YYARG.  If
   YYARG is null, return the number of expected tokens (guaranteed to
   be less than YYNTOKENS).  Return YYENOMEM on memory exhaustion.
   Return 0 if there are more than YYARGN expected tokens, yet fill
   YYARG up to YYARGN. */
static int
yypcontext_expected_tokens (const yypcontext_t *yyctx,
                            yysymbol_kind_t yyarg[], int yyargn)
{
  /* Actual size of YYARG. */
  int yycount = 0;
  int yyn = yypact[+*yyctx->yyssp];
  if (!yypact_value_is_default (yyn))
    {
      /* Start YYX at -YYN if negative to avoid negative indexes in
         YYCHECK.  In other words, skip the first -YYN actions for
         this state because they are default actions.  */
      int yyxbegin = yyn < 0 ? -yyn : 0;
      /* Stay within bounds of both yycheck and yytname.  */
      int yychecklim = YYLAST - yyn + 1;
      int yyxend = yychecklim < YYNTOKENS ? yychecklim : YYNTOKENS;
      int yyx;
      for (yyx = yyxbegin; yyx < yyxend; ++yyx)
        if (yycheck[yyx + yyn] == yyx && yyx != YYSYMBOL_YYerror
            && !yytable_value_is_error (yytable[yyx + yyn]))
          {
            if (!yyarg)
              ++yycount;
            else if (yycount == yyargn)
              return 0;
            else
              yyarg[yycount++] = YY_CAST (yysymbol_kind_t, yyx);
          }
    }
  if (yyarg && yycount == 0 && 0 < yyargn)
    yyarg[0] = YYSYMBOL_YYEMPTY;
  return yycount;
}




#ifndef yystrlen
# if defined __GLIBC__ && defined _STRING_H
#  define yystrlen(S) (YY_CAST (YYPTRDIFF_T, strlen (S)))
# else
/* Return the length of YYSTR.  */
static YYPTRDIFF_T
yystrlen (const char *yystr)
{
  YYPTRDIFF_T yylen;
  for (yylen = 0; yystr[yylen]; yylen++)
    continue;
  return yylen;
}
# endif
#endif

#ifndef yystpcpy
# if defined __GLIBC__ && defined _STRING_H && defined _GNU_SOURCE
#  define yystpcpy stpcpy
# else
/* Copy YYSRC to YYDEST, returning the address of the terminating '\0' in
   YYDEST.  */
static char *
yystpcpy (char *yydest, const char *yysrc)
{
  char *yyd = yydest;
  const char *yys = yysrc;

  while ((*yyd++ = *yys++) != '\0')
    continue;

  return yyd - 1;
}
# endif
#endif

#ifndef yytnamerr
/* Copy to YYRES the contents of YYSTR after stripping away unnecessary
   quotes and backslashes, so that it's suitable for yyerror.  The
   heuristic is that double-quoting is unnecessary unless the string
   contains an apostrophe, a comma, or backslash (other than
   backslash-backslash).  YYSTR is taken from yytname.  If YYRES is
   null, do not copy; instead, return the length of what the result
   would have been.  */
static YYPTRDIFF_T
yytnamerr (char *yyres, const char *yystr)
{
  if (*yystr == '"')
    {
      YYPTRDIFF_T yyn = 0;
      char const *yyp = yystr;
      for (;;)
        switch (*++yyp)
          {
          case '\'':
          case ',':
            goto do_not_strip_quotes;

          case '\\':
            if (*++yyp != '\\')
              goto do_not_strip_quotes;
            else
              goto append;

          append:
          default:
            if (yyres)
              yyres[yyn] = *yyp;
            yyn++;
            break;

          case '"':
            if (yyres)
              yyres[yyn] = '\0';
            return yyn;
          }
    do_not_strip_quotes: ;
    }

  if (yyres)
    return yystpcpy (yyres, yystr) - yyres;
  else
    return yystrlen (yystr);
}
#endif


static int
yy_syntax_error_arguments (const yypcontext_t *yyctx,
                           yysymbol_kind_t yyarg[], int yyargn)
{
  /* Actual size of YYARG. */
  int yycount = 0;
  /* There are many possibilities here to consider:
     - If this state is a consistent state with a default action, then
       the only way this function was invoked is if the default action
       is an error action.  In that case, don't check for expected
       tokens because there are none.
     - The only way there can be no lookahead present (in yychar) is if
       this state is a consistent state with a default action.  Thus,
       detecting the absence of a lookahead is sufficient to determine
       that there is no unexpected or expected token to report.  In that
       case, just report a simple "syntax error".
     - Don't assume there isn't a lookahead just because this state is a
       consistent state with a default action.  There might have been a
       previous inconsistent state, consistent state with a non-default
       action, or user semantic action that manipulated yychar.
     - Of course, the expected token list depends on states to have
       correct lookahead information, and it depends on the parser not
       to perform extra reductions after fetching a lookahead from the
       scanner and before detecting a syntax error.  Thus, state merging
       (from LALR or IELR) and default reductions corrupt the expected
       token list.  However, the list is correct for canonical LR with
       one exception: it will still contain any token that will not be
       accepted due to an error action in a later state.
  */
  if (yyctx->yytoken != YYSYMBOL_YYEMPTY)
    {
      int yyn;
      if (yyarg)
        yyarg[yycount] = yyctx->yytoken;
      ++yycount;
      yyn = yypcontext_expected_tokens (yyctx,
                                        yyarg ? yyarg + 1 : yyarg, yyargn - 1);
      if (yyn == YYENOMEM)
        return YYENOMEM;
      else
        yycount += yyn;
    }
  return yycount;
}

/* Copy into *YYMSG, which is of size *YYMSG_ALLOC, an error message
   about the unexpected token YYTOKEN for the state stack whose top is
   YYSSP.

   Return 0 if *YYMSG was successfully written.  Return -1 if *YYMSG is
   not large enough to hold the message.  In that case, also set
   *YYMSG_ALLOC to the required number of bytes.  Return YYENOMEM if the
   required number of bytes is too large to store.  */
static int
yysyntax_error (YYPTRDIFF_T *yymsg_alloc, char **yymsg,
                const yypcontext_t *yyctx)
{
  enum { YYARGS_MAX = 5 };
  /* Internationalized format string. */
  const char *yyformat = YY_NULLPTR;
  /* Arguments of yyformat: reported tokens (one for the "unexpected",
     one per "expected"). */
  yysymbol_kind_t yyarg[YYARGS_MAX];
  /* Cumulated lengths of YYARG.  */
  YYPTRDIFF_T yysize = 0;

  /* Actual size of YYARG. */
  int yycount = yy_syntax_error_arguments (yyctx, yyarg, YYARGS_MAX);
  if (yycount == YYENOMEM)
    return YYENOMEM;

  switch (yycount)
    {
#define YYCASE_(N, S)                       \
      case N:                               \
        yyformat = S;                       \
        break
    default: /* Avoid compiler warnings. */
      YYCASE_(0, YY_("syntax error"));
      YYCASE_(1, YY_("syntax error, unexpected %s"));
      YYCASE_(2, YY_("syntax error, unexpected %s, expecting %s"));
      YYCASE_(3, YY_("syntax error, unexpected %s, expecting %s or %s"));
      YYCASE_(4, YY_("syntax error, unexpected %s, expecting %s or %s or %s"));
      YYCASE_(5, YY_("syntax error, unexpected %s, expecting %s or %s or %s or %s"));
#undef YYCASE_
    }

  /* Compute error message size.  Don't count the "%s"s, but reserve
     room for the terminator.  */
  yysize = yystrlen (yyformat) - 2 * yycount + 1;
  {
    int yyi;
    for (yyi = 0; yyi < yycount; ++yyi)
      {
        YYPTRDIFF_T yysize1
          = yysize + yytnamerr (YY_NULLPTR, yytname[yyarg[yyi]]);
        if (yysize <= yysize1 && yysize1 <= YYSTACK_ALLOC_MAXIMUM)
          yysize = yysize1;
        else
          return YYENOMEM;
      }
  }

  if (*yymsg_alloc < yysize)
    {
      *yymsg_alloc = 2 * yysize;
      if (! (yysize <= *yymsg_alloc
             && *yymsg_alloc <= YYSTACK_ALLOC_MAXIMUM))
        *yymsg_alloc = YYSTACK_ALLOC_MAXIMUM;
      return -1;
    }

  /* Avoid sprintf, as that infringes on the user's name space.
     Don't have undefined behavior even if the translation
     produced a string with the wrong number of "%s"s.  */
  {
    char *yyp = *yymsg;
    int yyi = 0;
    while ((*yyp = *yyformat) != '\0')
      if (*yyp == '%' && yyformat[1] == 's' && yyi < yycount)
        {
          yyp += yytnamerr (yyp, yytname[yyarg[yyi++]]);
          yyformat += 2;
        }
      else
        {
          ++yyp;
          ++yyformat;
        }
  }
  return 0;
}


/*-----------------------------------------------.
| Release the memory associated to this symbol.  |
`-----------------------------------------------*/

static void
yydestruct (const char *yymsg,
            yysymbol_kind_t yykind, YYSTYPE *yyvaluep)
{
  YY_USE (yyvaluep);
  if (!yymsg)
    yymsg = "Deleting";
  YY_SYMBOL_PRINT (yymsg, yykind, yyvaluep, yylocationp);

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  YY_USE (yykind);
  YY_IGNORE_MAYBE_UNINITIALIZED_END
}


/* Lookahead token kind.  */
int yychar;

/* The semantic value of the lookahead symbol.  */
YYSTYPE yylval;
/* Number of syntax errors so far.  */
int yynerrs;




/*----------.
| yyparse.  |
`----------*/

int
yyparse (void)
{
    yy_state_fast_t yystate = 0;
    /* Number of tokens to shift before error messages enabled.  */
    int yyerrstatus = 0;

    /* Refer to the stacks through separate pointers, to allow yyoverflow
       to reallocate them elsewhere.  */

    /* Their size.  */
    YYPTRDIFF_T yystacksize = YYINITDEPTH;

    /* The state stack: array, bottom, top.  */
    yy_state_t yyssa[YYINITDEPTH];
    yy_state_t *yyss = yyssa;
    yy_state_t *yyssp = yyss;

    /* The semantic value stack: array, bottom, top.  */
    YYSTYPE yyvsa[YYINITDEPTH];
    YYSTYPE *yyvs = yyvsa;
    YYSTYPE *yyvsp = yyvs;

  int yyn;
  /* The return value of yyparse.  */
  int yyresult;
  /* Lookahead symbol kind.  */
  yysymbol_kind_t yytoken = YYSYMBOL_YYEMPTY;
  /* The variables used to return semantic value and location from the
     action routines.  */
  YYSTYPE yyval;

  /* Buffer for error messages, and its allocated size.  */
  char yymsgbuf[128];
  char *yymsg = yymsgbuf;
  YYPTRDIFF_T yymsg_alloc = sizeof yymsgbuf;

#define YYPOPSTACK(N)   (yyvsp -= (N), yyssp -= (N))

  /* The number of symbols on the RHS of the reduced rule.
     Keep to zero when no symbol should be popped.  */
  int yylen = 0;

  YYDPRINTF ((stderr, "Starting parse\n"));

  yychar = YYEMPTY; /* Cause a token to be read.  */

  goto yysetstate;


/*------------------------------------------------------------.
| yynewstate -- push a new state, which is found in yystate.  |
`------------------------------------------------------------*/
yynewstate:
  /* In all cases, when you get here, the value and location stacks
     have just been pushed.  So pushing a state here evens the stacks.  */
  yyssp++;


/*--------------------------------------------------------------------.
| yysetstate -- set current state (the top of the stack) to yystate.  |
`--------------------------------------------------------------------*/
yysetstate:
  YYDPRINTF ((stderr, "Entering state %d\n", yystate));
  YY_ASSERT (0 <= yystate && yystate < YYNSTATES);
  YY_IGNORE_USELESS_CAST_BEGIN
  *yyssp = YY_CAST (yy_state_t, yystate);
  YY_IGNORE_USELESS_CAST_END
  YY_STACK_PRINT (yyss, yyssp);

  if (yyss + yystacksize - 1 <= yyssp)
#if !defined yyoverflow && !defined YYSTACK_RELOCATE
    YYNOMEM;
#else
    {
      /* Get the current used size of the three stacks, in elements.  */
      YYPTRDIFF_T yysize = yyssp - yyss + 1;

# if defined yyoverflow
      {
        /* Give user a chance to reallocate the stack.  Use copies of
           these so that the &'s don't force the real ones into
           memory.  */
        yy_state_t *yyss1 = yyss;
        YYSTYPE *yyvs1 = yyvs;

        /* Each stack pointer address is followed by the size of the
           data in use in that stack, in bytes.  This used to be a
           conditional around just the two extra args, but that might
           be undefined if yyoverflow is a macro.  */
        yyoverflow (YY_("memory exhausted"),
                    &yyss1, yysize * YYSIZEOF (*yyssp),
                    &yyvs1, yysize * YYSIZEOF (*yyvsp),
                    &yystacksize);
        yyss = yyss1;
        yyvs = yyvs1;
      }
# else /* defined YYSTACK_RELOCATE */
      /* Extend the stack our own way.  */
      if (YYMAXDEPTH <= yystacksize)
        YYNOMEM;
      yystacksize *= 2;
      if (YYMAXDEPTH < yystacksize)
        yystacksize = YYMAXDEPTH;

      {
        yy_state_t *yyss1 = yyss;
        union yyalloc *yyptr =
          YY_CAST (union yyalloc *,
                   YYSTACK_ALLOC (YY_CAST (YYSIZE_T, YYSTACK_BYTES (yystacksize))));
        if (! yyptr)
          YYNOMEM;
        YYSTACK_RELOCATE (yyss_alloc, yyss);
        YYSTACK_RELOCATE (yyvs_alloc, yyvs);
#  undef YYSTACK_RELOCATE
        if (yyss1 != yyssa)
          YYSTACK_FREE (yyss1);
      }
# endif

      yyssp = yyss + yysize - 1;
      yyvsp = yyvs + yysize - 1;

      YY_IGNORE_USELESS_CAST_BEGIN
      YYDPRINTF ((stderr, "Stack size increased to %ld\n",
                  YY_CAST (long, yystacksize)));
      YY_IGNORE_USELESS_CAST_END

      if (yyss + yystacksize - 1 <= yyssp)
        YYABORT;
    }
#endif /* !defined yyoverflow && !defined YYSTACK_RELOCATE */


  if (yystate == YYFINAL)
    YYACCEPT;

  goto yybackup;


/*-----------.
| yybackup.  |
`-----------*/
yybackup:
  /* Do appropriate processing given the current state.  Read a
     lookahead token if we need one and don't already have one.  */

  /* First try to decide what to do without reference to lookahead token.  */
  yyn = yypact[yystate];
  if (yypact_value_is_default (yyn))
    goto yydefault;

  /* Not known => get a lookahead token if don't already have one.  */

  /* YYCHAR is either empty, or end-of-input, or a valid lookahead.  */
  if (yychar == YYEMPTY)
    {
      YYDPRINTF ((stderr, "Reading a token\n"));
      yychar = yylex ();
    }

  if (yychar <= YYEOF)
    {
      yychar = YYEOF;
      yytoken = YYSYMBOL_YYEOF;
      YYDPRINTF ((stderr, "Now at end of input.\n"));
    }
  else if (yychar == YYerror)
    {
      /* The scanner already issued an error message, process directly
         to error recovery.  But do not keep the error token as
         lookahead, it is too special and may lead us to an endless
         loop in error recovery. */
      yychar = YYUNDEF;
      yytoken = YYSYMBOL_YYerror;
      goto yyerrlab1;
    }
  else
    {
      yytoken = YYTRANSLATE (yychar);
      YY_SYMBOL_PRINT ("Next token is", yytoken, &yylval, &yylloc);
    }

  /* If the proper action on seeing token YYTOKEN is to reduce or to
     detect an error, take that action.  */
  yyn += yytoken;
  if (yyn < 0 || YYLAST < yyn || yycheck[yyn] != yytoken)
    goto yydefault;
  yyn = yytable[yyn];
  if (yyn <= 0)
    {
      if (yytable_value_is_error (yyn))
        goto yyerrlab;
      yyn = -yyn;
      goto yyreduce;
    }

  /* Count tokens shifted since error; after three, turn off error
     status.  */
  if (yyerrstatus)
    yyerrstatus--;

  /* Shift the lookahead token.  */
  YY_SYMBOL_PRINT ("Shifting", yytoken, &yylval, &yylloc);
  yystate = yyn;
  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END

  /* Discard the shifted token.  */
  yychar = YYEMPTY;
  goto yynewstate;


/*-----------------------------------------------------------.
| yydefault -- do the default action for the current state.  |
`-----------------------------------------------------------*/
yydefault:
  yyn = yydefact[yystate];
  if (yyn == 0)
    goto yyerrlab;
  goto yyreduce;


/*-----------------------------.
| yyreduce -- do a reduction.  |
`-----------------------------*/
yyreduce:
  /* yyn is the number of a rule to reduce with.  */
  yylen = yyr2[yyn];

  /* If YYLEN is nonzero, implement the default value of the action:
     '$$ = $1'.

     Otherwise, the following line sets YYVAL to garbage.
     This behavior is undocumented and Bison
     users should not rely upon it.  Assigning to YYVAL
     unconditionally makes the parser a bit smaller, and it avoids a
     GCC warning that YYVAL may be used uninitialized.  */
  yyval = yyvsp[1-yylen];


  YY_REDUCE_PRINT (yyn);
  switch (yyn)
    {
  case 2: /* start: header_list  */
#line 57 "parser.ypp"
                { ast = new ProgramImpl(yyvsp[0].u_proc_list); }
#line 1533 "parser.cpp"
    break;

  case 3: /* header_list: header_list header  */
#line 61 "parser.ypp"
                                {
        yyvsp[-1].u_proc_list->push_back(yyvsp[0].u_proc);
        yyval = yyvsp[-1];
    }
#line 1542 "parser.cpp"
    break;

  case 4: /* header_list: header  */
#line 65 "parser.ypp"
             {
        yyval.u_proc_list=new std::list<Proc_ptr>();
        yyval.u_proc_list->push_back(yyvsp[0].u_proc);
    }
#line 1551 "parser.cpp"
    break;

  case 5: /* header: PROCEDURE WORD '(' func_param ')' RETURN types '{' func_body '}'  */
#line 71 "parser.ypp"
                                                                         { yyval.u_proc=new ProcImpl(new SymName(yyvsp[-8].u_base_charptr), yyvsp[-6].u_decl_list, yyvsp[-3].u_type, yyvsp[-1].u_procedure_block); }
#line 1557 "parser.cpp"
    break;

  case 6: /* func_param: %empty  */
#line 76 "parser.ypp"
    { yyval.u_decl_list=new std::list<Decl_ptr>(); }
#line 1563 "parser.cpp"
    break;

  case 7: /* func_param: list_func_param ':' types  */
#line 77 "parser.ypp"
                                {
        yyval.u_decl_list=new std::list<Decl_ptr>();
        (yyval.u_decl_list)->push_back(new DeclImpl(yyvsp[-2].u_symname_list,yyvsp[0].u_type));
    }
#line 1572 "parser.cpp"
    break;

  case 8: /* func_param: func_param ';' list_func_param ':' types  */
#line 81 "parser.ypp"
                                               {
        (yyvsp[-4].u_decl_list)->push_back(new DeclImpl(yyvsp[-2].u_symname_list,yyvsp[0].u_type));
        yyval=yyvsp[-4];
    }
#line 1581 "parser.cpp"
    break;

  case 9: /* list_func_param: list_func_param ',' WORD  */
#line 89 "parser.ypp"
                             {
        (yyvsp[-2].u_symname_list)->push_back(new SymName(yyvsp[0].u_base_charptr));
        yyval=yyvsp[-2];
    }
#line 1590 "parser.cpp"
    break;

  case 10: /* list_func_param: WORD  */
#line 94 "parser.ypp"
    {
        yyval.u_symname_list=new std::list<SymName_ptr>();
        (yyval.u_symname_list)->push_back(new SymName(yyvsp[0].u_base_charptr));
    }
#line 1599 "parser.cpp"
    break;

  case 11: /* func_body: checks_header get_var checks_list RETURN expression ';'  */
#line 101 "parser.ypp"
                                                                   {
        yyval.u_procedure_block=new Procedure_blockImpl(yyvsp[-5].u_proc_list,yyvsp[-4].u_decl_list,yyvsp[-3].u_stat_list,new Return(yyvsp[-1].u_expr));
    }
#line 1607 "parser.cpp"
    break;

  case 13: /* checks_list: %empty  */
#line 108 "parser.ypp"
             { yyval.u_stat_list=new std::list<Stat_ptr>(); }
#line 1613 "parser.cpp"
    break;

  case 14: /* checks_list: checks_list checks  */
#line 109 "parser.ypp"
                         {
        (yyvsp[-1].u_stat_list)->push_back(yyvsp[0].u_stat);
        yyval=yyvsp[-1];
    }
#line 1622 "parser.cpp"
    break;

  case 15: /* checks_header: %empty  */
#line 115 "parser.ypp"
               { yyval.u_proc_list=new std::list<Proc_ptr>(); }
#line 1628 "parser.cpp"
    break;

  case 16: /* checks_header: checks_header header  */
#line 116 "parser.ypp"
                           {
        (yyvsp[-1].u_proc_list)->push_back(yyvsp[0].u_proc);
        yyval=yyvsp[-1];
    }
#line 1637 "parser.cpp"
    break;

  case 17: /* checks: expression_check '=' expression ';'  */
#line 124 "parser.ypp"
                                            { yyval.u_stat=new Assignment(yyvsp[-3].u_lhs,yyvsp[-1].u_expr); }
#line 1643 "parser.cpp"
    break;

  case 18: /* checks: expression_check '=' STRING ';'  */
#line 125 "parser.ypp"
                                      { yyval.u_stat=new StringAssignment(yyvsp[-3].u_lhs,new StringPrimitive(yyvsp[-1].u_base_charptr)); }
#line 1649 "parser.cpp"
    break;

  case 19: /* checks: expression_check '=' WORD '(' expression_list ')' ';'  */
#line 126 "parser.ypp"
                                                            { yyval.u_stat=new Call(yyvsp[-6].u_lhs,new SymName(yyvsp[-4].u_base_charptr),yyvsp[-2].u_expr_list); }
#line 1655 "parser.cpp"
    break;

  case 20: /* checks: WORD '(' expression_list ')' ';'  */
#line 127 "parser.ypp"
                                       { yyval.u_stat=new Call(yyvsp[-4].u_lhs,new SymName(yyvsp[-2].u_base_charptr),yyvsp[0].u_expr_list); }
#line 1661 "parser.cpp"
    break;

  case 22: /* checks: '{' nested_list '}'  */
#line 129 "parser.ypp"
                          { yyval.u_stat=new CodeBlock(yyvsp[-1].u_nested_block); }
#line 1667 "parser.cpp"
    break;

  case 23: /* nested_list: get_var checks_list  */
#line 133 "parser.ypp"
                                 {
        yyval.u_nested_block=new Nested_blockImpl(yyvsp[-1].u_decl_list,yyvsp[0].u_stat_list);
    }
#line 1675 "parser.cpp"
    break;

  case 24: /* expression_list: %empty  */
#line 138 "parser.ypp"
                 { yyval.u_expr_list=new std::list<Expr_ptr>(); }
#line 1681 "parser.cpp"
    break;

  case 25: /* expression_list: expression  */
#line 139 "parser.ypp"
                 {
        yyval.u_expr_list=new std::list<Expr_ptr>();
        (yyval.u_expr_list)->push_back(yyvsp[0].u_expr);
    }
#line 1690 "parser.cpp"
    break;

  case 26: /* expression_list: expression_list ',' expression  */
#line 143 "parser.ypp"
                                     { (yyval.u_expr_list)->push_back(yyvsp[0].u_expr); }
#line 1696 "parser.cpp"
    break;

  case 28: /* expression: '-' expression  */
#line 145 "parser.ypp"
                     { yyval.u_expr=new Uminus(yyvsp[0].u_expr); }
#line 1702 "parser.cpp"
    break;

  case 29: /* expression: '^' expression  */
#line 146 "parser.ypp"
                     { yyval.u_expr=new Deref(yyvsp[0].u_expr); }
#line 1708 "parser.cpp"
    break;

  case 30: /* expression: '!' expression  */
#line 147 "parser.ypp"
                     { yyval.u_expr=new Not(yyvsp[0].u_expr); }
#line 1714 "parser.cpp"
    break;

  case 31: /* expression: '&' expression_check  */
#line 148 "parser.ypp"
                           { yyval.u_expr=new AddressOf(yyvsp[0].u_lhs); }
#line 1720 "parser.cpp"
    break;

  case 34: /* expression: WORD '[' expression ']'  */
#line 151 "parser.ypp"
                              { yyval.u_lhs=new ArrayElement(new SymName(yyvsp[-3].u_base_charptr),yyvsp[-1].u_expr); }
#line 1726 "parser.cpp"
    break;

  case 35: /* expression: WORD  */
#line 152 "parser.ypp"
           { yyval.u_expr=new Ident(new SymName(yyvsp[0].u_base_charptr)); }
#line 1732 "parser.cpp"
    break;

  case 36: /* expression: CHAR  */
#line 153 "parser.ypp"
           { yyval.u_expr=new CharLit(new Primitive(yyvsp[0].u_base_int)); }
#line 1738 "parser.cpp"
    break;

  case 37: /* expression: BOOLEAN  */
#line 154 "parser.ypp"
              { yyval.u_expr=new BoolLit(new Primitive(yyvsp[0].u_base_int)); }
#line 1744 "parser.cpp"
    break;

  case 38: /* expression: INTEGER  */
#line 155 "parser.ypp"
              { yyval.u_expr=new IntLit(new Primitive(yyvsp[0].u_base_int)); }
#line 1750 "parser.cpp"
    break;

  case 39: /* expression: _NULL_  */
#line 156 "parser.ypp"
             { yyval.u_expr=new NullLit(); }
#line 1756 "parser.cpp"
    break;

  case 40: /* expression_check: WORD  */
#line 160 "parser.ypp"
                       { yyval.u_lhs=new Variable(new SymName(yyvsp[0].u_base_charptr)); }
#line 1762 "parser.cpp"
    break;

  case 41: /* expression_check: WORD '[' expression ']'  */
#line 161 "parser.ypp"
                              { yyval.u_lhs=new ArrayElement(new SymName(yyvsp[-3].u_base_charptr),yyvsp[-1].u_expr); }
#line 1768 "parser.cpp"
    break;

  case 42: /* expression_check: '^' WORD  */
#line 162 "parser.ypp"
               { yyval.u_lhs=new DerefVariable(new SymName(yyvsp[0].u_base_charptr)); }
#line 1774 "parser.cpp"
    break;

  case 43: /* get_var: %empty  */
#line 166 "parser.ypp"
         { yyval.u_decl_list=new std::list<Decl_ptr>(); }
#line 1780 "parser.cpp"
    break;

  case 44: /* get_var: get_var VAR list_func_param ':' types ';'  */
#line 167 "parser.ypp"
                                                {
        (yyvsp[-5].u_decl_list)->push_back(new DeclImpl(yyvsp[-3].u_symname_list,yyvsp[-1].u_type));
        yyval = yyvsp[-5];
    }
#line 1789 "parser.cpp"
    break;

  case 45: /* get_var: get_var VAR list_func_param ':' STRING '[' INTEGER ']' ';'  */
#line 171 "parser.ypp"
                                                                 {
        (yyvsp[-8].u_decl_list)->push_back(new DeclImpl(yyvsp[-6].u_symname_list,new TString(new Primitive(yyvsp[-2].u_base_int))));
        yyval = yyvsp[-8];
    }
#line 1798 "parser.cpp"
    break;

  case 46: /* keywords: IF '(' expression ')' '{' nested_list '}'  */
#line 178 "parser.ypp"
                                                     { yyval.u_stat=new IfNoElse(yyvsp[-4].u_expr,yyvsp[-1].u_nested_block); }
#line 1804 "parser.cpp"
    break;

  case 47: /* keywords: IF '(' expression ')' '{' nested_list '}' ELSE '{' nested_list '}'  */
#line 179 "parser.ypp"
                                                                         { yyval.u_stat=new IfWithElse(yyvsp[-8].u_expr,yyvsp[-5].u_nested_block,yyvsp[-1].u_nested_block); }
#line 1810 "parser.cpp"
    break;

  case 48: /* keywords: WHILE '(' expression ')' '{' nested_list '}'  */
#line 180 "parser.ypp"
                                                   { yyval.u_stat=new WhileLoop(yyvsp[-4].u_expr,yyvsp[-1].u_nested_block); }
#line 1816 "parser.cpp"
    break;

  case 49: /* types: STRING  */
#line 184 "parser.ypp"
               { yyval.u_type=new TString(new Primitive(yyvsp[0].u_base_int)); }
#line 1822 "parser.cpp"
    break;

  case 50: /* types: INTEGER  */
#line 185 "parser.ypp"
              { yyval.u_type=new TInteger(); }
#line 1828 "parser.cpp"
    break;

  case 51: /* types: BOOLEAN  */
#line 186 "parser.ypp"
              { yyval.u_type=new TBoolean(); }
#line 1834 "parser.cpp"
    break;

  case 52: /* types: CHAR  */
#line 187 "parser.ypp"
           { yyval.u_type=new TCharacter(); }
#line 1840 "parser.cpp"
    break;

  case 53: /* types: INTPTR  */
#line 188 "parser.ypp"
             { yyval.u_type=new TIntPtr(); }
#line 1846 "parser.cpp"
    break;

  case 54: /* types: CHARPTR  */
#line 189 "parser.ypp"
              { yyval.u_type=new TCharPtr(); }
#line 1852 "parser.cpp"
    break;

  case 55: /* operator: expression AND expression  */
#line 193 "parser.ypp"
                                     { yyval.u_expr=new And(yyvsp[-2].u_expr,yyvsp[0].u_expr); }
#line 1858 "parser.cpp"
    break;

  case 56: /* operator: expression '/' expression  */
#line 194 "parser.ypp"
                                { yyval.u_expr=new Div(yyvsp[-2].u_expr,yyvsp[0].u_expr); }
#line 1864 "parser.cpp"
    break;

  case 57: /* operator: expression '=' expression  */
#line 195 "parser.ypp"
                                { yyval.u_stat=new Assignment(yyvsp[-2].u_lhs,yyvsp[0].u_expr); }
#line 1870 "parser.cpp"
    break;

  case 58: /* operator: expression EQUAL expression  */
#line 196 "parser.ypp"
                                  { yyval.u_expr=new Compare(yyvsp[-2].u_expr,yyvsp[0].u_expr); }
#line 1876 "parser.cpp"
    break;

  case 59: /* operator: expression '>' expression  */
#line 197 "parser.ypp"
                                { yyval.u_expr=new Gt(yyvsp[-2].u_expr,yyvsp[0].u_expr); }
#line 1882 "parser.cpp"
    break;

  case 60: /* operator: expression EQUALMORE expression  */
#line 198 "parser.ypp"
                                      { yyval.u_expr=new Gteq(yyvsp[-2].u_expr,yyvsp[0].u_expr); }
#line 1888 "parser.cpp"
    break;

  case 61: /* operator: expression '<' expression  */
#line 199 "parser.ypp"
                                { yyval.u_expr=new Lt(yyvsp[-2].u_expr,yyvsp[0].u_expr); }
#line 1894 "parser.cpp"
    break;

  case 62: /* operator: expression EQUALLESS expression  */
#line 200 "parser.ypp"
                                      { yyval.u_expr=new Lteq(yyvsp[-2].u_expr,yyvsp[0].u_expr); }
#line 1900 "parser.cpp"
    break;

  case 63: /* operator: expression DIFF expression  */
#line 201 "parser.ypp"
                                 { yyval.u_expr=new Noteq(yyvsp[-2].u_expr,yyvsp[0].u_expr); }
#line 1906 "parser.cpp"
    break;

  case 64: /* operator: expression OR expression  */
#line 202 "parser.ypp"
                               { yyval.u_expr=new Or(yyvsp[-2].u_expr,yyvsp[0].u_expr); }
#line 1912 "parser.cpp"
    break;

  case 65: /* operator: expression '-' expression  */
#line 203 "parser.ypp"
                                { yyval.u_expr=new Minus(yyvsp[-2].u_expr,yyvsp[0].u_expr); }
#line 1918 "parser.cpp"
    break;

  case 66: /* operator: expression '+' expression  */
#line 204 "parser.ypp"
                                { yyval.u_expr=new Plus(yyvsp[-2].u_expr,yyvsp[0].u_expr); }
#line 1924 "parser.cpp"
    break;

  case 67: /* operator: expression '*' expression  */
#line 205 "parser.ypp"
                                { yyval.u_expr=new Times(yyvsp[-2].u_expr,yyvsp[0].u_expr); }
#line 1930 "parser.cpp"
    break;

  case 68: /* paranthesis: '|' expression '|'  */
#line 209 "parser.ypp"
                                 { yyval.u_expr=new AbsoluteValue(yyvsp[-1].u_expr); }
#line 1936 "parser.cpp"
    break;

  case 69: /* paranthesis: '(' expression ')'  */
#line 210 "parser.ypp"
                         { yyval.u_expr=yyvsp[-1].u_expr; }
#line 1942 "parser.cpp"
    break;


#line 1946 "parser.cpp"

      default: break;
    }
  /* User semantic actions sometimes alter yychar, and that requires
     that yytoken be updated with the new translation.  We take the
     approach of translating immediately before every use of yytoken.
     One alternative is translating here after every semantic action,
     but that translation would be missed if the semantic action invokes
     YYABORT, YYACCEPT, or YYERROR immediately after altering yychar or
     if it invokes YYBACKUP.  In the case of YYABORT or YYACCEPT, an
     incorrect destructor might then be invoked immediately.  In the
     case of YYERROR or YYBACKUP, subsequent parser actions might lead
     to an incorrect destructor call or verbose syntax error message
     before the lookahead is translated.  */
  YY_SYMBOL_PRINT ("-> $$ =", YY_CAST (yysymbol_kind_t, yyr1[yyn]), &yyval, &yyloc);

  YYPOPSTACK (yylen);
  yylen = 0;

  *++yyvsp = yyval;

  /* Now 'shift' the result of the reduction.  Determine what state
     that goes to, based on the state we popped back to and the rule
     number reduced by.  */
  {
    const int yylhs = yyr1[yyn] - YYNTOKENS;
    const int yyi = yypgoto[yylhs] + *yyssp;
    yystate = (0 <= yyi && yyi <= YYLAST && yycheck[yyi] == *yyssp
               ? yytable[yyi]
               : yydefgoto[yylhs]);
  }

  goto yynewstate;


/*--------------------------------------.
| yyerrlab -- here on detecting error.  |
`--------------------------------------*/
yyerrlab:
  /* Make sure we have latest lookahead translation.  See comments at
     user semantic actions for why this is necessary.  */
  yytoken = yychar == YYEMPTY ? YYSYMBOL_YYEMPTY : YYTRANSLATE (yychar);
  /* If not already recovering from an error, report this error.  */
  if (!yyerrstatus)
    {
      ++yynerrs;
      {
        yypcontext_t yyctx
          = {yyssp, yytoken};
        char const *yymsgp = YY_("syntax error");
        int yysyntax_error_status;
        yysyntax_error_status = yysyntax_error (&yymsg_alloc, &yymsg, &yyctx);
        if (yysyntax_error_status == 0)
          yymsgp = yymsg;
        else if (yysyntax_error_status == -1)
          {
            if (yymsg != yymsgbuf)
              YYSTACK_FREE (yymsg);
            yymsg = YY_CAST (char *,
                             YYSTACK_ALLOC (YY_CAST (YYSIZE_T, yymsg_alloc)));
            if (yymsg)
              {
                yysyntax_error_status
                  = yysyntax_error (&yymsg_alloc, &yymsg, &yyctx);
                yymsgp = yymsg;
              }
            else
              {
                yymsg = yymsgbuf;
                yymsg_alloc = sizeof yymsgbuf;
                yysyntax_error_status = YYENOMEM;
              }
          }
        yyerror (yymsgp);
        if (yysyntax_error_status == YYENOMEM)
          YYNOMEM;
      }
    }

  if (yyerrstatus == 3)
    {
      /* If just tried and failed to reuse lookahead token after an
         error, discard it.  */

      if (yychar <= YYEOF)
        {
          /* Return failure if at end of input.  */
          if (yychar == YYEOF)
            YYABORT;
        }
      else
        {
          yydestruct ("Error: discarding",
                      yytoken, &yylval);
          yychar = YYEMPTY;
        }
    }

  /* Else will try to reuse lookahead token after shifting the error
     token.  */
  goto yyerrlab1;


/*---------------------------------------------------.
| yyerrorlab -- error raised explicitly by YYERROR.  |
`---------------------------------------------------*/
yyerrorlab:
  /* Pacify compilers when the user code never invokes YYERROR and the
     label yyerrorlab therefore never appears in user code.  */
  if (0)
    YYERROR;
  ++yynerrs;

  /* Do not reclaim the symbols of the rule whose action triggered
     this YYERROR.  */
  YYPOPSTACK (yylen);
  yylen = 0;
  YY_STACK_PRINT (yyss, yyssp);
  yystate = *yyssp;
  goto yyerrlab1;


/*-------------------------------------------------------------.
| yyerrlab1 -- common code for both syntax error and YYERROR.  |
`-------------------------------------------------------------*/
yyerrlab1:
  yyerrstatus = 3;      /* Each real token shifted decrements this.  */

  /* Pop stack until we find a state that shifts the error token.  */
  for (;;)
    {
      yyn = yypact[yystate];
      if (!yypact_value_is_default (yyn))
        {
          yyn += YYSYMBOL_YYerror;
          if (0 <= yyn && yyn <= YYLAST && yycheck[yyn] == YYSYMBOL_YYerror)
            {
              yyn = yytable[yyn];
              if (0 < yyn)
                break;
            }
        }

      /* Pop the current state because it cannot handle the error token.  */
      if (yyssp == yyss)
        YYABORT;


      yydestruct ("Error: popping",
                  YY_ACCESSING_SYMBOL (yystate), yyvsp);
      YYPOPSTACK (1);
      yystate = *yyssp;
      YY_STACK_PRINT (yyss, yyssp);
    }

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END


  /* Shift the error token.  */
  YY_SYMBOL_PRINT ("Shifting", YY_ACCESSING_SYMBOL (yyn), yyvsp, yylsp);

  yystate = yyn;
  goto yynewstate;


/*-------------------------------------.
| yyacceptlab -- YYACCEPT comes here.  |
`-------------------------------------*/
yyacceptlab:
  yyresult = 0;
  goto yyreturnlab;


/*-----------------------------------.
| yyabortlab -- YYABORT comes here.  |
`-----------------------------------*/
yyabortlab:
  yyresult = 1;
  goto yyreturnlab;


/*-----------------------------------------------------------.
| yyexhaustedlab -- YYNOMEM (memory exhaustion) comes here.  |
`-----------------------------------------------------------*/
yyexhaustedlab:
  yyerror (YY_("memory exhausted"));
  yyresult = 2;
  goto yyreturnlab;


/*----------------------------------------------------------.
| yyreturnlab -- parsing is finished, clean up and return.  |
`----------------------------------------------------------*/
yyreturnlab:
  if (yychar != YYEMPTY)
    {
      /* Make sure we have latest lookahead translation.  See comments at
         user semantic actions for why this is necessary.  */
      yytoken = YYTRANSLATE (yychar);
      yydestruct ("Cleanup: discarding lookahead",
                  yytoken, &yylval);
    }
  /* Do not reclaim the symbols of the rule whose action triggered
     this YYABORT or YYACCEPT.  */
  YYPOPSTACK (yylen);
  YY_STACK_PRINT (yyss, yyssp);
  while (yyssp != yyss)
    {
      yydestruct ("Cleanup: popping",
                  YY_ACCESSING_SYMBOL (+*yyssp), yyvsp);
      YYPOPSTACK (1);
    }
#ifndef yyoverflow
  if (yyss != yyssa)
    YYSTACK_FREE (yyss);
#endif
  if (yymsg != yymsgbuf)
    YYSTACK_FREE (yymsg);
  return yyresult;
}

#line 212 "parser.ypp"


/** You shall not pass!
 *  You should not  have to do or edit anything past this.
 */

extern int yylineno;

void yyerror(const char *s)
{
    fprintf(stderr, "%s at line %d\n", s, yylineno);
    return;
}
