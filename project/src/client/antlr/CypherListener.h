
// Generated from Cypher.g4 by ANTLR 4.13.1

#pragma once


#include "antlr4-runtime.h"
#include "CypherParser.h"


/**
 * This interface defines an abstract listener for a parse tree produced by CypherParser.
 */
class  CypherListener : public antlr4::tree::ParseTreeListener {
public:

  virtual void enterOC_Cypher(CypherParser::OC_CypherContext *ctx) = 0;
  virtual void exitOC_Cypher(CypherParser::OC_CypherContext *ctx) = 0;

  virtual void enterOC_Statement(CypherParser::OC_StatementContext *ctx) = 0;
  virtual void exitOC_Statement(CypherParser::OC_StatementContext *ctx) = 0;

  virtual void enterOC_Query(CypherParser::OC_QueryContext *ctx) = 0;
  virtual void exitOC_Query(CypherParser::OC_QueryContext *ctx) = 0;

  virtual void enterOC_RegularQuery(CypherParser::OC_RegularQueryContext *ctx) = 0;
  virtual void exitOC_RegularQuery(CypherParser::OC_RegularQueryContext *ctx) = 0;

  virtual void enterOC_Union(CypherParser::OC_UnionContext *ctx) = 0;
  virtual void exitOC_Union(CypherParser::OC_UnionContext *ctx) = 0;

  virtual void enterOC_SingleQuery(CypherParser::OC_SingleQueryContext *ctx) = 0;
  virtual void exitOC_SingleQuery(CypherParser::OC_SingleQueryContext *ctx) = 0;

  virtual void enterOC_SinglePartQuery(CypherParser::OC_SinglePartQueryContext *ctx) = 0;
  virtual void exitOC_SinglePartQuery(CypherParser::OC_SinglePartQueryContext *ctx) = 0;

  virtual void enterOC_MultiPartQuery(CypherParser::OC_MultiPartQueryContext *ctx) = 0;
  virtual void exitOC_MultiPartQuery(CypherParser::OC_MultiPartQueryContext *ctx) = 0;

  virtual void enterOC_UpdatingClause(CypherParser::OC_UpdatingClauseContext *ctx) = 0;
  virtual void exitOC_UpdatingClause(CypherParser::OC_UpdatingClauseContext *ctx) = 0;

  virtual void enterOC_ReadingClause(CypherParser::OC_ReadingClauseContext *ctx) = 0;
  virtual void exitOC_ReadingClause(CypherParser::OC_ReadingClauseContext *ctx) = 0;

  virtual void enterOC_Match(CypherParser::OC_MatchContext *ctx) = 0;
  virtual void exitOC_Match(CypherParser::OC_MatchContext *ctx) = 0;

  virtual void enterOC_Unwind(CypherParser::OC_UnwindContext *ctx) = 0;
  virtual void exitOC_Unwind(CypherParser::OC_UnwindContext *ctx) = 0;

  virtual void enterOC_Merge(CypherParser::OC_MergeContext *ctx) = 0;
  virtual void exitOC_Merge(CypherParser::OC_MergeContext *ctx) = 0;

  virtual void enterOC_MergeAction(CypherParser::OC_MergeActionContext *ctx) = 0;
  virtual void exitOC_MergeAction(CypherParser::OC_MergeActionContext *ctx) = 0;

  virtual void enterOC_Create(CypherParser::OC_CreateContext *ctx) = 0;
  virtual void exitOC_Create(CypherParser::OC_CreateContext *ctx) = 0;

  virtual void enterOC_Set(CypherParser::OC_SetContext *ctx) = 0;
  virtual void exitOC_Set(CypherParser::OC_SetContext *ctx) = 0;

  virtual void enterOC_SetItem(CypherParser::OC_SetItemContext *ctx) = 0;
  virtual void exitOC_SetItem(CypherParser::OC_SetItemContext *ctx) = 0;

  virtual void enterOC_Delete(CypherParser::OC_DeleteContext *ctx) = 0;
  virtual void exitOC_Delete(CypherParser::OC_DeleteContext *ctx) = 0;

  virtual void enterOC_Remove(CypherParser::OC_RemoveContext *ctx) = 0;
  virtual void exitOC_Remove(CypherParser::OC_RemoveContext *ctx) = 0;

  virtual void enterOC_RemoveItem(CypherParser::OC_RemoveItemContext *ctx) = 0;
  virtual void exitOC_RemoveItem(CypherParser::OC_RemoveItemContext *ctx) = 0;

  virtual void enterOC_InQueryCall(CypherParser::OC_InQueryCallContext *ctx) = 0;
  virtual void exitOC_InQueryCall(CypherParser::OC_InQueryCallContext *ctx) = 0;

  virtual void enterOC_StandaloneCall(CypherParser::OC_StandaloneCallContext *ctx) = 0;
  virtual void exitOC_StandaloneCall(CypherParser::OC_StandaloneCallContext *ctx) = 0;

  virtual void enterOC_YieldItems(CypherParser::OC_YieldItemsContext *ctx) = 0;
  virtual void exitOC_YieldItems(CypherParser::OC_YieldItemsContext *ctx) = 0;

  virtual void enterOC_YieldItem(CypherParser::OC_YieldItemContext *ctx) = 0;
  virtual void exitOC_YieldItem(CypherParser::OC_YieldItemContext *ctx) = 0;

  virtual void enterOC_With(CypherParser::OC_WithContext *ctx) = 0;
  virtual void exitOC_With(CypherParser::OC_WithContext *ctx) = 0;

  virtual void enterOC_Return(CypherParser::OC_ReturnContext *ctx) = 0;
  virtual void exitOC_Return(CypherParser::OC_ReturnContext *ctx) = 0;

  virtual void enterOC_ProjectionBody(CypherParser::OC_ProjectionBodyContext *ctx) = 0;
  virtual void exitOC_ProjectionBody(CypherParser::OC_ProjectionBodyContext *ctx) = 0;

  virtual void enterOC_ProjectionItems(CypherParser::OC_ProjectionItemsContext *ctx) = 0;
  virtual void exitOC_ProjectionItems(CypherParser::OC_ProjectionItemsContext *ctx) = 0;

  virtual void enterOC_ProjectionItem(CypherParser::OC_ProjectionItemContext *ctx) = 0;
  virtual void exitOC_ProjectionItem(CypherParser::OC_ProjectionItemContext *ctx) = 0;

  virtual void enterOC_Order(CypherParser::OC_OrderContext *ctx) = 0;
  virtual void exitOC_Order(CypherParser::OC_OrderContext *ctx) = 0;

  virtual void enterOC_Skip(CypherParser::OC_SkipContext *ctx) = 0;
  virtual void exitOC_Skip(CypherParser::OC_SkipContext *ctx) = 0;

  virtual void enterOC_Limit(CypherParser::OC_LimitContext *ctx) = 0;
  virtual void exitOC_Limit(CypherParser::OC_LimitContext *ctx) = 0;

  virtual void enterOC_SortItem(CypherParser::OC_SortItemContext *ctx) = 0;
  virtual void exitOC_SortItem(CypherParser::OC_SortItemContext *ctx) = 0;

  virtual void enterOC_Where(CypherParser::OC_WhereContext *ctx) = 0;
  virtual void exitOC_Where(CypherParser::OC_WhereContext *ctx) = 0;

  virtual void enterOC_Pattern(CypherParser::OC_PatternContext *ctx) = 0;
  virtual void exitOC_Pattern(CypherParser::OC_PatternContext *ctx) = 0;

  virtual void enterOC_PatternPart(CypherParser::OC_PatternPartContext *ctx) = 0;
  virtual void exitOC_PatternPart(CypherParser::OC_PatternPartContext *ctx) = 0;

  virtual void enterOC_AnonymousPatternPart(CypherParser::OC_AnonymousPatternPartContext *ctx) = 0;
  virtual void exitOC_AnonymousPatternPart(CypherParser::OC_AnonymousPatternPartContext *ctx) = 0;

  virtual void enterOC_PatternElement(CypherParser::OC_PatternElementContext *ctx) = 0;
  virtual void exitOC_PatternElement(CypherParser::OC_PatternElementContext *ctx) = 0;

  virtual void enterOC_RelationshipsPattern(CypherParser::OC_RelationshipsPatternContext *ctx) = 0;
  virtual void exitOC_RelationshipsPattern(CypherParser::OC_RelationshipsPatternContext *ctx) = 0;

  virtual void enterOC_NodePattern(CypherParser::OC_NodePatternContext *ctx) = 0;
  virtual void exitOC_NodePattern(CypherParser::OC_NodePatternContext *ctx) = 0;

  virtual void enterOC_PatternElementChain(CypherParser::OC_PatternElementChainContext *ctx) = 0;
  virtual void exitOC_PatternElementChain(CypherParser::OC_PatternElementChainContext *ctx) = 0;

  virtual void enterOC_RelationshipPattern(CypherParser::OC_RelationshipPatternContext *ctx) = 0;
  virtual void exitOC_RelationshipPattern(CypherParser::OC_RelationshipPatternContext *ctx) = 0;

  virtual void enterOC_RelationshipDetail(CypherParser::OC_RelationshipDetailContext *ctx) = 0;
  virtual void exitOC_RelationshipDetail(CypherParser::OC_RelationshipDetailContext *ctx) = 0;

  virtual void enterOC_Properties(CypherParser::OC_PropertiesContext *ctx) = 0;
  virtual void exitOC_Properties(CypherParser::OC_PropertiesContext *ctx) = 0;

  virtual void enterOC_RelationshipTypes(CypherParser::OC_RelationshipTypesContext *ctx) = 0;
  virtual void exitOC_RelationshipTypes(CypherParser::OC_RelationshipTypesContext *ctx) = 0;

  virtual void enterOC_NodeLabels(CypherParser::OC_NodeLabelsContext *ctx) = 0;
  virtual void exitOC_NodeLabels(CypherParser::OC_NodeLabelsContext *ctx) = 0;

  virtual void enterOC_NodeLabel(CypherParser::OC_NodeLabelContext *ctx) = 0;
  virtual void exitOC_NodeLabel(CypherParser::OC_NodeLabelContext *ctx) = 0;

  virtual void enterOC_RangeLiteral(CypherParser::OC_RangeLiteralContext *ctx) = 0;
  virtual void exitOC_RangeLiteral(CypherParser::OC_RangeLiteralContext *ctx) = 0;

  virtual void enterOC_LabelName(CypherParser::OC_LabelNameContext *ctx) = 0;
  virtual void exitOC_LabelName(CypherParser::OC_LabelNameContext *ctx) = 0;

  virtual void enterOC_RelTypeName(CypherParser::OC_RelTypeNameContext *ctx) = 0;
  virtual void exitOC_RelTypeName(CypherParser::OC_RelTypeNameContext *ctx) = 0;

  virtual void enterOC_PropertyExpression(CypherParser::OC_PropertyExpressionContext *ctx) = 0;
  virtual void exitOC_PropertyExpression(CypherParser::OC_PropertyExpressionContext *ctx) = 0;

  virtual void enterOC_Expression(CypherParser::OC_ExpressionContext *ctx) = 0;
  virtual void exitOC_Expression(CypherParser::OC_ExpressionContext *ctx) = 0;

  virtual void enterOC_OrExpression(CypherParser::OC_OrExpressionContext *ctx) = 0;
  virtual void exitOC_OrExpression(CypherParser::OC_OrExpressionContext *ctx) = 0;

  virtual void enterOC_XorExpression(CypherParser::OC_XorExpressionContext *ctx) = 0;
  virtual void exitOC_XorExpression(CypherParser::OC_XorExpressionContext *ctx) = 0;

  virtual void enterOC_AndExpression(CypherParser::OC_AndExpressionContext *ctx) = 0;
  virtual void exitOC_AndExpression(CypherParser::OC_AndExpressionContext *ctx) = 0;

  virtual void enterOC_NotExpression(CypherParser::OC_NotExpressionContext *ctx) = 0;
  virtual void exitOC_NotExpression(CypherParser::OC_NotExpressionContext *ctx) = 0;

  virtual void enterOC_ComparisonExpression(CypherParser::OC_ComparisonExpressionContext *ctx) = 0;
  virtual void exitOC_ComparisonExpression(CypherParser::OC_ComparisonExpressionContext *ctx) = 0;

  virtual void enterOC_PartialComparisonExpression(CypherParser::OC_PartialComparisonExpressionContext *ctx) = 0;
  virtual void exitOC_PartialComparisonExpression(CypherParser::OC_PartialComparisonExpressionContext *ctx) = 0;

  virtual void enterOC_StringListNullPredicateExpression(CypherParser::OC_StringListNullPredicateExpressionContext *ctx) = 0;
  virtual void exitOC_StringListNullPredicateExpression(CypherParser::OC_StringListNullPredicateExpressionContext *ctx) = 0;

  virtual void enterOC_StringPredicateExpression(CypherParser::OC_StringPredicateExpressionContext *ctx) = 0;
  virtual void exitOC_StringPredicateExpression(CypherParser::OC_StringPredicateExpressionContext *ctx) = 0;

  virtual void enterOC_ListPredicateExpression(CypherParser::OC_ListPredicateExpressionContext *ctx) = 0;
  virtual void exitOC_ListPredicateExpression(CypherParser::OC_ListPredicateExpressionContext *ctx) = 0;

  virtual void enterOC_NullPredicateExpression(CypherParser::OC_NullPredicateExpressionContext *ctx) = 0;
  virtual void exitOC_NullPredicateExpression(CypherParser::OC_NullPredicateExpressionContext *ctx) = 0;

  virtual void enterOC_AddOrSubtractExpression(CypherParser::OC_AddOrSubtractExpressionContext *ctx) = 0;
  virtual void exitOC_AddOrSubtractExpression(CypherParser::OC_AddOrSubtractExpressionContext *ctx) = 0;

  virtual void enterOC_MultiplyDivideModuloExpression(CypherParser::OC_MultiplyDivideModuloExpressionContext *ctx) = 0;
  virtual void exitOC_MultiplyDivideModuloExpression(CypherParser::OC_MultiplyDivideModuloExpressionContext *ctx) = 0;

  virtual void enterOC_PowerOfExpression(CypherParser::OC_PowerOfExpressionContext *ctx) = 0;
  virtual void exitOC_PowerOfExpression(CypherParser::OC_PowerOfExpressionContext *ctx) = 0;

  virtual void enterOC_UnaryAddOrSubtractExpression(CypherParser::OC_UnaryAddOrSubtractExpressionContext *ctx) = 0;
  virtual void exitOC_UnaryAddOrSubtractExpression(CypherParser::OC_UnaryAddOrSubtractExpressionContext *ctx) = 0;

  virtual void enterOC_NonArithmeticOperatorExpression(CypherParser::OC_NonArithmeticOperatorExpressionContext *ctx) = 0;
  virtual void exitOC_NonArithmeticOperatorExpression(CypherParser::OC_NonArithmeticOperatorExpressionContext *ctx) = 0;

  virtual void enterOC_ListOperatorExpression(CypherParser::OC_ListOperatorExpressionContext *ctx) = 0;
  virtual void exitOC_ListOperatorExpression(CypherParser::OC_ListOperatorExpressionContext *ctx) = 0;

  virtual void enterOC_PropertyLookup(CypherParser::OC_PropertyLookupContext *ctx) = 0;
  virtual void exitOC_PropertyLookup(CypherParser::OC_PropertyLookupContext *ctx) = 0;

  virtual void enterOC_Atom(CypherParser::OC_AtomContext *ctx) = 0;
  virtual void exitOC_Atom(CypherParser::OC_AtomContext *ctx) = 0;

  virtual void enterOC_CaseExpression(CypherParser::OC_CaseExpressionContext *ctx) = 0;
  virtual void exitOC_CaseExpression(CypherParser::OC_CaseExpressionContext *ctx) = 0;

  virtual void enterOC_CaseAlternative(CypherParser::OC_CaseAlternativeContext *ctx) = 0;
  virtual void exitOC_CaseAlternative(CypherParser::OC_CaseAlternativeContext *ctx) = 0;

  virtual void enterOC_ListComprehension(CypherParser::OC_ListComprehensionContext *ctx) = 0;
  virtual void exitOC_ListComprehension(CypherParser::OC_ListComprehensionContext *ctx) = 0;

  virtual void enterOC_PatternComprehension(CypherParser::OC_PatternComprehensionContext *ctx) = 0;
  virtual void exitOC_PatternComprehension(CypherParser::OC_PatternComprehensionContext *ctx) = 0;

  virtual void enterOC_Quantifier(CypherParser::OC_QuantifierContext *ctx) = 0;
  virtual void exitOC_Quantifier(CypherParser::OC_QuantifierContext *ctx) = 0;

  virtual void enterOC_FilterExpression(CypherParser::OC_FilterExpressionContext *ctx) = 0;
  virtual void exitOC_FilterExpression(CypherParser::OC_FilterExpressionContext *ctx) = 0;

  virtual void enterOC_PatternPredicate(CypherParser::OC_PatternPredicateContext *ctx) = 0;
  virtual void exitOC_PatternPredicate(CypherParser::OC_PatternPredicateContext *ctx) = 0;

  virtual void enterOC_ParenthesizedExpression(CypherParser::OC_ParenthesizedExpressionContext *ctx) = 0;
  virtual void exitOC_ParenthesizedExpression(CypherParser::OC_ParenthesizedExpressionContext *ctx) = 0;

  virtual void enterOC_IdInColl(CypherParser::OC_IdInCollContext *ctx) = 0;
  virtual void exitOC_IdInColl(CypherParser::OC_IdInCollContext *ctx) = 0;

  virtual void enterOC_FunctionInvocation(CypherParser::OC_FunctionInvocationContext *ctx) = 0;
  virtual void exitOC_FunctionInvocation(CypherParser::OC_FunctionInvocationContext *ctx) = 0;

  virtual void enterOC_FunctionName(CypherParser::OC_FunctionNameContext *ctx) = 0;
  virtual void exitOC_FunctionName(CypherParser::OC_FunctionNameContext *ctx) = 0;

  virtual void enterOC_ExistentialSubquery(CypherParser::OC_ExistentialSubqueryContext *ctx) = 0;
  virtual void exitOC_ExistentialSubquery(CypherParser::OC_ExistentialSubqueryContext *ctx) = 0;

  virtual void enterOC_ExplicitProcedureInvocation(CypherParser::OC_ExplicitProcedureInvocationContext *ctx) = 0;
  virtual void exitOC_ExplicitProcedureInvocation(CypherParser::OC_ExplicitProcedureInvocationContext *ctx) = 0;

  virtual void enterOC_ImplicitProcedureInvocation(CypherParser::OC_ImplicitProcedureInvocationContext *ctx) = 0;
  virtual void exitOC_ImplicitProcedureInvocation(CypherParser::OC_ImplicitProcedureInvocationContext *ctx) = 0;

  virtual void enterOC_ProcedureResultField(CypherParser::OC_ProcedureResultFieldContext *ctx) = 0;
  virtual void exitOC_ProcedureResultField(CypherParser::OC_ProcedureResultFieldContext *ctx) = 0;

  virtual void enterOC_ProcedureName(CypherParser::OC_ProcedureNameContext *ctx) = 0;
  virtual void exitOC_ProcedureName(CypherParser::OC_ProcedureNameContext *ctx) = 0;

  virtual void enterOC_Namespace(CypherParser::OC_NamespaceContext *ctx) = 0;
  virtual void exitOC_Namespace(CypherParser::OC_NamespaceContext *ctx) = 0;

  virtual void enterOC_Variable(CypherParser::OC_VariableContext *ctx) = 0;
  virtual void exitOC_Variable(CypherParser::OC_VariableContext *ctx) = 0;

  virtual void enterOC_Literal(CypherParser::OC_LiteralContext *ctx) = 0;
  virtual void exitOC_Literal(CypherParser::OC_LiteralContext *ctx) = 0;

  virtual void enterOC_BooleanLiteral(CypherParser::OC_BooleanLiteralContext *ctx) = 0;
  virtual void exitOC_BooleanLiteral(CypherParser::OC_BooleanLiteralContext *ctx) = 0;

  virtual void enterOC_NumberLiteral(CypherParser::OC_NumberLiteralContext *ctx) = 0;
  virtual void exitOC_NumberLiteral(CypherParser::OC_NumberLiteralContext *ctx) = 0;

  virtual void enterOC_IntegerLiteral(CypherParser::OC_IntegerLiteralContext *ctx) = 0;
  virtual void exitOC_IntegerLiteral(CypherParser::OC_IntegerLiteralContext *ctx) = 0;

  virtual void enterOC_DoubleLiteral(CypherParser::OC_DoubleLiteralContext *ctx) = 0;
  virtual void exitOC_DoubleLiteral(CypherParser::OC_DoubleLiteralContext *ctx) = 0;

  virtual void enterOC_ListLiteral(CypherParser::OC_ListLiteralContext *ctx) = 0;
  virtual void exitOC_ListLiteral(CypherParser::OC_ListLiteralContext *ctx) = 0;

  virtual void enterOC_MapLiteral(CypherParser::OC_MapLiteralContext *ctx) = 0;
  virtual void exitOC_MapLiteral(CypherParser::OC_MapLiteralContext *ctx) = 0;

  virtual void enterOC_PropertyKeyName(CypherParser::OC_PropertyKeyNameContext *ctx) = 0;
  virtual void exitOC_PropertyKeyName(CypherParser::OC_PropertyKeyNameContext *ctx) = 0;

  virtual void enterOC_Parameter(CypherParser::OC_ParameterContext *ctx) = 0;
  virtual void exitOC_Parameter(CypherParser::OC_ParameterContext *ctx) = 0;

  virtual void enterOC_SchemaName(CypherParser::OC_SchemaNameContext *ctx) = 0;
  virtual void exitOC_SchemaName(CypherParser::OC_SchemaNameContext *ctx) = 0;

  virtual void enterOC_ReservedWord(CypherParser::OC_ReservedWordContext *ctx) = 0;
  virtual void exitOC_ReservedWord(CypherParser::OC_ReservedWordContext *ctx) = 0;

  virtual void enterOC_SymbolicName(CypherParser::OC_SymbolicNameContext *ctx) = 0;
  virtual void exitOC_SymbolicName(CypherParser::OC_SymbolicNameContext *ctx) = 0;

  virtual void enterOC_LeftArrowHead(CypherParser::OC_LeftArrowHeadContext *ctx) = 0;
  virtual void exitOC_LeftArrowHead(CypherParser::OC_LeftArrowHeadContext *ctx) = 0;

  virtual void enterOC_RightArrowHead(CypherParser::OC_RightArrowHeadContext *ctx) = 0;
  virtual void exitOC_RightArrowHead(CypherParser::OC_RightArrowHeadContext *ctx) = 0;

  virtual void enterOC_Dash(CypherParser::OC_DashContext *ctx) = 0;
  virtual void exitOC_Dash(CypherParser::OC_DashContext *ctx) = 0;


};

