#pragma once 

#include <iostream>
#include <array>

struct EarningsInfo {
    char ticker[8];
    std::array<long double, 5> fiveYearRevenue, fiveYearEarnings, fiveYearEBITDA, fiveYearOperatingExpenses;
    double EPS;
    long long sharesOutstanding;
};

struct BalanceSheetInfo {
    char ticker[8];
    long long currentAssets, PPE, totalAssets, currentLiabilities, totalLiabilities, equity;
};

struct CashFlowInfo {
    char ticker[8];
    long double netIncome, cashFlowFromOps, cashFromInvesting, cashFromFinancing, netCashFlow, stockComp, dividendsPaid;
};

struct Company {
    char ticker[8];
    EarningsInfo earnings;
    BalanceSheetInfo balanceSheet;
    CashFlowInfo cashFlow;
};

struct Ratios {
    char ticker[8];
    double debtToCapital, operatingMargin, grossMargin, netMargin, ebitMargin, ROE, assetTurnover;
};

struct ValuationMetrics {
    char ticker[8];
    double peRatio, forwardPE, pbRatio, psRatio, evToEBITDA, evToRevenue, pegRatio;
    double currentPrice, marketCap, enterpriseValue;
};

struct TechnicalIndicators {
    char ticker[8];
    double movingAvg50Day, movingAvg200Day, relativeStrengthIndex, beta, averageVolume;
    double percentFromHighs, percentFromLows, volatility, sharpeRatio;
};

struct DividendInfo {
    char ticker[8];
    double dividendYield, dividendPerShare, payoutRatio;
    int dividendGrowthYears;
    double fiveYearDividendGrowth;
    char exDividendDate[12], paymentDate[12];
    double dividendCoverage;
};

struct AnalystEstimates {
    char ticker[8];
    int numAnalysts;
    double consensusRecommendation, avgPriceTarget, highPriceTarget, lowPriceTarget;
    double nextEarningsEstimate, nextYearEstimate, fiveYearGrowthEstimate, surprisePercentage;
};

struct OwnershipInfo {
    char ticker[8];
    double insiderOwnership, institutionalOwnership, shortInterest, shortRatio;
    int institutionalHolders;
    double recentInsiderBuying, sharesFloat;
};

struct GrowthMetrics {
    char ticker[8];
    double revenueGrowthYOY, earningsGrowthYOY, ebitdaGrowthYOY;
    double revenueCAGR3Yr, earningsCAGR3Yr, dividendCAGR3Yr, bookValueGrowth, freeCashFlowGrowth;
};

struct IndustryMetrics {
    char industryName[24], sectorName[16];
    double avgPE, avgPB, avgROE, avgMargin, avgDividendYield, sectorPerformanceYTD, marketShare;
    int industryRank;
};

struct RiskMetrics {
    char ticker[8];
    double debtToEBITDA, interestCoverage, altmanZScore, beneishMScore, liquidityRatio;
    double pitroskiFScore, standardDeviation, maxDrawdown;
};

struct HistoricalPricePoint {
    char ticker[8];
    char date[12];
    double open, high, low, close, adjustedClose;
    long volume;
};