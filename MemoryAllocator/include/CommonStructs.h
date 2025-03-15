#pragma once 

#include <iostream>
#include <array>

const int TICKER_SIZE = 8;

enum class InfoType {
    EARNINGS_INFO,
    BALANCE_SHEET_INFO,
    CASH_FLOW_INFO,
    COMPANY,
    RATIOS,
    VALUATION_METRICS,
    TECHNICAL_INDICATORS,
    DIVIDEND_INFO,
    ANALYST_ESTIMATES,
    OWNERSHIP_INFO,
    GROWTH_METRICS,
    INDUSTRY_METRICS,
    RISK_METRICS,
    HISTORICAL_PRICE_POINT
};

struct EarningsInfo {
    char ticker[TICKER_SIZE];
    std::array<long double, 5> fiveYearRevenue, fiveYearEarnings, fiveYearEBITDA, fiveYearOperatingExpenses;
    double EPS;
    long long sharesOutstanding;
};

struct BalanceSheetInfo {
    char ticker[TICKER_SIZE];
    long long currentAssets, PPE, totalAssets, currentLiabilities, totalLiabilities, equity;
};

struct CashFlowInfo {
    char ticker[TICKER_SIZE];
    long double netIncome, cashFlowFromOps, cashFromInvesting, cashFromFinancing, netCashFlow, stockComp, dividendsPaid;
};

struct Company {
    int insertId;
    char ticker[TICKER_SIZE];
    EarningsInfo earnings;
    BalanceSheetInfo balanceSheet;
    CashFlowInfo cashFlow;
};

struct Ratios {
    char ticker[TICKER_SIZE];
    double debtToCapital, operatingMargin, grossMargin, netMargin, ebitMargin, ROE, assetTurnover;
};

struct ValuationMetrics {
    char ticker[TICKER_SIZE];
    double peRatio, forwardPE, pbRatio, psRatio, evToEBITDA, evToRevenue, pegRatio;
    double currentPrice, marketCap, enterpriseValue;
};

struct TechnicalIndicators {
    char ticker[TICKER_SIZE];
    double movingAvg50Day, movingAvg200Day, relativeStrengthIndex, beta, averageVolume;
    double percentFromHighs, percentFromLows, volatility, sharpeRatio;
};

struct DividendInfo {
    char ticker[TICKER_SIZE];
    double dividendYield, dividendPerShare, payoutRatio;
    int dividendGrowthYears;
    double fiveYearDividendGrowth;
    char exDividendDate[12], paymentDate[12];
    double dividendCoverage;
};

struct AnalystEstimates {
    char ticker[TICKER_SIZE];
    int numAnalysts;
    double consensusRecommendation, avgPriceTarget, highPriceTarget, lowPriceTarget;
    double nextEarningsEstimate, nextYearEstimate, fiveYearGrowthEstimate, surprisePercentage;
};

struct OwnershipInfo {
    char ticker[TICKER_SIZE];
    double insiderOwnership, institutionalOwnership, shortInterest, shortRatio;
    int institutionalHolders;
    double recentInsiderBuying, sharesFloat;
};

struct GrowthMetrics {
    char ticker[TICKER_SIZE];
    double revenueGrowthYOY, earningsGrowthYOY, ebitdaGrowthYOY;
    double revenueCAGR3Yr, earningsCAGR3Yr, dividendCAGR3Yr, bookValueGrowth, freeCashFlowGrowth;
};

struct IndustryMetrics {
    char ticker[TICKER_SIZE];
    char industryName[24], sectorName[16];
    double avgPE, avgPB, avgROE, avgMargin, avgDividendYield, sectorPerformanceYTD, marketShare;
    int industryRank;
};

struct RiskMetrics {
    char ticker[TICKER_SIZE];
    double debtToEBITDA, interestCoverage, altmanZScore, beneishMScore, liquidityRatio;
    double pitroskiFScore, standardDeviation, maxDrawdown;
};

struct HistoricalPricePoint {
    char ticker[TICKER_SIZE];
    char date[12];
    double open, high, low, close, adjustedClose;
    long volume;
};