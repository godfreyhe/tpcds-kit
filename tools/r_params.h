/* 
 * Legal Notice 
 * 
 * This document and associated source code (the "Work") is a part of a 
 * benchmark specification maintained by the TPC. 
 * 
 * The TPC reserves all right, title, and interest to the Work as provided 
 * under U.S. and international laws, including without limitation all patent 
 * and trademark rights therein. 
 * 
 * No Warranty 
 * 
 * 1.1 TO THE MAXIMUM EXTENT PERMITTED BY APPLICABLE LAW, THE INFORMATION 
 *     CONTAINED HEREIN IS PROVIDED "AS IS" AND WITH ALL FAULTS, AND THE 
 *     AUTHORS AND DEVELOPERS OF THE WORK HEREBY DISCLAIM ALL OTHER 
 *     WARRANTIES AND CONDITIONS, EITHER EXPRESS, IMPLIED OR STATUTORY, 
 *     INCLUDING, BUT NOT LIMITED TO, ANY (IF ANY) IMPLIED WARRANTIES, 
 *     DUTIES OR CONDITIONS OF MERCHANTABILITY, OF FITNESS FOR A PARTICULAR 
 *     PURPOSE, OF ACCURACY OR COMPLETENESS OF RESPONSES, OF RESULTS, OF 
 *     WORKMANLIKE EFFORT, OF LACK OF VIRUSES, AND OF LACK OF NEGLIGENCE. 
 *     ALSO, THERE IS NO WARRANTY OR CONDITION OF TITLE, QUIET ENJOYMENT, 
 *     QUIET POSSESSION, CORRESPONDENCE TO DESCRIPTION OR NON-INFRINGEMENT 
 *     WITH REGARD TO THE WORK. 
 * 1.2 IN NO EVENT WILL ANY AUTHOR OR DEVELOPER OF THE WORK BE LIABLE TO 
 *     ANY OTHER PARTY FOR ANY DAMAGES, INCLUDING BUT NOT LIMITED TO THE 
 *     COST OF PROCURING SUBSTITUTE GOODS OR SERVICES, LOST PROFITS, LOSS 
 *     OF USE, LOSS OF DATA, OR ANY INCIDENTAL, CONSEQUENTIAL, DIRECT, 
 *     INDIRECT, OR SPECIAL DAMAGES WHETHER UNDER CONTRACT, TORT, WARRANTY,
 *     OR OTHERWISE, ARISING IN ANY WAY OUT OF THIS OR ANY OTHER AGREEMENT 
 *     RELATING TO THE WORK, WHETHER OR NOT SUCH AUTHOR OR DEVELOPER HAD 
 *     ADVANCE NOTICE OF THE POSSIBILITY OF SUCH DAMAGES. 
 * 
 * Contributors:
 * Gradient Systems
 */ 

#ifndef R_PARAMS_H
#define R_PARAMS_H
#define OPT_NONE    0x00 
#define OPT_FLG     0x01 /* option is a flag; no parameter */
#define OPT_INT     0x02 /* argument is an integer */
#define OPT_STR     0x04 /* argument is a string */
#define OPT_NOP     0x08 /* flags non-operational options */
#define OPT_SUB     0x10 /* sub-option defined */
#define OPT_ADV		0x20 /* advanced option */
#define OPT_SET		0x40 /* not changeable -- used for default/file/command precedence */
#define OPT_DFLT	0x80 /* param set to non-zero default */
#define OPT_MULTI	0x100 /* param may be set repeatedly */
#define OPT_HIDE	0x200 /* hidden option -- not listed in usage */
#define TYPE_MASK   0x07

typedef struct OPTION_T
	{
	char    *name;
	int     flags;
	int     index;
	char    *usage;
	int     (*action)(char *szPName, char *optarg);
	char	*dflt;
	} option_t;
#endif
/*
 * function declarations
 */
int	process_options(int count, char **args);
char	*get_str(char *var);
void	set_str(char *param, char *value);
int		get_int(char *var);
void	set_int(char *var, char *val);
void    set_flg(char *var);
int		is_set(char *flag);
void	clr_flg(char *flag);
int		find_table(char *szParamName, char *tname);
int		read_file(char *param_name, char *arg);
int		usage(char *param_name, char *msg);
char	*GetParamName(int nParam);
char	*GetParamValue(int nParam);
int		load_param(int nParam, char *value);
int		fnd_param(char *name);
int		init_params(void);
int		set_option(char *pname, char *value);
void	load_params(void);
int		IsIntParam(char *szName);
int		IsStrParam(char *szName);
