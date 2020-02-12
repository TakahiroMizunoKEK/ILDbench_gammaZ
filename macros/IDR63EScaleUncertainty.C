void IDR63EScaleUncertainty()
{
//=========Macro generated from canvas: c39/c39
//=========  (Mon Jun  3 01:00:29 2019) by ROOT version6.08/06
   TCanvas *c39 = new TCanvas("c39", "c39",0,22,600,600);
   gStyle->SetOptFit(1);
   c39->Range(-28.12,-76.00097,307.88,346.2266);
   c39->SetFillColor(10);
   c39->SetBorderMode(0);
   c39->SetBorderSize(2);
   c39->SetTickx(1);
   c39->SetTicky(1);
   c39->SetLeftMargin(0.17);
   c39->SetRightMargin(0.08);
   c39->SetTopMargin(0.08);
   c39->SetBottomMargin(0.18);
   c39->SetFrameLineWidth(3);
   c39->SetFrameBorderMode(0);
   c39->SetFrameLineWidth(3);
   c39->SetFrameBorderMode(0);
   
   Double_t Graph0_fx1001[6] = {
   140,
   170,
   190,
   210,
   230,
   250};
   Double_t Graph0_fy1001[6] = {
   73.9585,
   54.79332,
   45.63903,
   30.31754,
   14.71736,
   12.98384};
   Double_t Graph0_fex1001[6] = {
   20,
   10,
   10,
   10,
   10,
   10};
   Double_t Graph0_fey1001[6] = {
   7.229618,
   3.674659,
   2.655205,
   0.8854699,
   0.2062626,
   0.1904206};
   TGraphErrors *gre = new TGraphErrors(6,Graph0_fx1001,Graph0_fy1001,Graph0_fex1001,Graph0_fey1001);
   gre->SetName("Graph0");
   gre->SetTitle("");
   gre->SetFillColor(1);

   Int_t ci;      // for color index setting
   TColor *color; // for color definition with alpha
   ci = TColor::GetColor("#0000ff");
   gre->SetLineColor(ci);
   gre->SetLineWidth(3);

   ci = TColor::GetColor("#0000ff");
   gre->SetMarkerColor(ci);
   gre->SetMarkerStyle(21);
   gre->SetMarkerSize(0.7);
   
   TH1F *Graph_Graph1001 = new TH1F("Graph_Graph1001","",100,109,271);
   Graph_Graph1001->SetMinimum(0);
   Graph_Graph1001->SetMaximum(100.);
   Graph_Graph1001->SetDirectory(0);
   Graph_Graph1001->SetStats(0);
   Graph_Graph1001->SetLineWidth(3);
   Graph_Graph1001->SetMarkerStyle(21);
   Graph_Graph1001->SetMarkerSize(0.5);
   Graph_Graph1001->GetXaxis()->SetTitle("E_{#gamma} (GeV)");
   Graph_Graph1001->GetXaxis()->SetNdivisions(506);
   Graph_Graph1001->GetXaxis()->SetLabelFont(42);
   Graph_Graph1001->GetXaxis()->SetLabelOffset(0.015);
   Graph_Graph1001->GetXaxis()->SetLabelSize(0.06);
   Graph_Graph1001->GetXaxis()->SetTitleSize(0.07);
   Graph_Graph1001->GetXaxis()->SetTitleFont(42);
   Graph_Graph1001->GetYaxis()->SetTitle("E_{#gamma} Scale Uncertainty (MeV)");
   Graph_Graph1001->GetYaxis()->SetNdivisions(506);
   Graph_Graph1001->GetYaxis()->SetLabelFont(42);
   Graph_Graph1001->GetYaxis()->SetLabelOffset(0.015);
   Graph_Graph1001->GetYaxis()->SetLabelSize(0.06);
   Graph_Graph1001->GetYaxis()->SetTitleSize(0.07);
   Graph_Graph1001->GetYaxis()->SetTitleOffset(1.1);
   Graph_Graph1001->GetYaxis()->SetTitleFont(42);
   Graph_Graph1001->GetZaxis()->SetLabelFont(42);
   Graph_Graph1001->GetZaxis()->SetLabelOffset(0.015);
   Graph_Graph1001->GetZaxis()->SetLabelSize(0.06);
   Graph_Graph1001->GetZaxis()->SetTitleSize(0.07);
   Graph_Graph1001->GetZaxis()->SetTitleOffset(1.1);
   Graph_Graph1001->GetZaxis()->SetTitleFont(42);
   gre->SetHistogram(Graph_Graph1001);
   
   gre->Draw("ap");
   
   Double_t Graph1_fx1002[6] = {
   140,
   170,
   190,
   210,
   230,
   250};
   Double_t Graph1_fy1002[6] = {
   77.17131,
   66.26617,
   47.61518,
   32.63275,
   15.36371,
   14.05122};
   Double_t Graph1_fex1002[6] = {
   20,
   10,
   10,
   10,
   10,
   10};
   Double_t Graph1_fey1002[6] = {
   7.577165,
   5.079551,
   2.536338,
   1.057833,
   0.2217749,
   0.2391932};
   gre = new TGraphErrors(6,Graph1_fx1002,Graph1_fy1002,Graph1_fex1002,Graph1_fey1002);
   gre->SetName("Graph1");
   gre->SetTitle("Graph");
   gre->SetFillColor(1);

   ci = TColor::GetColor("#ff0000");
   gre->SetLineColor(ci);
   gre->SetLineWidth(3);

   ci = TColor::GetColor("#ff0000");
   gre->SetMarkerColor(ci);
   gre->SetMarkerStyle(21);
   gre->SetMarkerSize(0.7);
   
   TH1F *Graph_Graph1002 = new TH1F("Graph_Graph1002","Graph",100,109,271);
   Graph_Graph1002->SetMinimum(0);
   Graph_Graph1002->SetMaximum(100.);
   Graph_Graph1002->SetDirectory(0);
   Graph_Graph1002->SetStats(0);
   Graph_Graph1002->SetLineWidth(3);
   Graph_Graph1002->SetMarkerStyle(21);
   Graph_Graph1002->SetMarkerSize(0.5);
   Graph_Graph1002->GetXaxis()->SetNdivisions(506);
   Graph_Graph1002->GetXaxis()->SetLabelFont(42);
   Graph_Graph1002->GetXaxis()->SetLabelOffset(0.015);
   Graph_Graph1002->GetXaxis()->SetLabelSize(0.06);
   Graph_Graph1002->GetXaxis()->SetTitleSize(0.07);
   Graph_Graph1002->GetXaxis()->SetTitleFont(42);
   Graph_Graph1002->GetYaxis()->SetNdivisions(506);
   Graph_Graph1002->GetYaxis()->SetLabelFont(42);
   Graph_Graph1002->GetYaxis()->SetLabelOffset(0.015);
   Graph_Graph1002->GetYaxis()->SetLabelSize(0.06);
   Graph_Graph1002->GetYaxis()->SetTitleSize(0.07);
   Graph_Graph1002->GetYaxis()->SetTitleOffset(1.1);
   Graph_Graph1002->GetYaxis()->SetTitleFont(42);
   Graph_Graph1002->GetZaxis()->SetLabelFont(42);
   Graph_Graph1002->GetZaxis()->SetLabelOffset(0.015);
   Graph_Graph1002->GetZaxis()->SetLabelSize(0.06);
   Graph_Graph1002->GetZaxis()->SetTitleSize(0.07);
   Graph_Graph1002->GetZaxis()->SetTitleOffset(1.1);
   Graph_Graph1002->GetZaxis()->SetTitleFont(42);
   gre->SetHistogram(Graph_Graph1002);
   
   gre->Draw("p ");
   TLatex *   tex = new TLatex(190,88,"ILD preliminary");
   tex->SetLineWidth(2);
   tex->Draw();
   
   TLegend *leg = new TLegend(0.75,0.72,0.9,0.81,NULL,"brNDC");
   leg->SetBorderSize(0);
   leg->SetTextFont(62);
   leg->SetTextSize(0.04);
   leg->SetLineColor(1);
   leg->SetLineStyle(1);
   leg->SetLineWidth(3);
   leg->SetFillColor(0);
   leg->SetFillStyle(1001);
   TLegendEntry *entry=leg->AddEntry("Graph0","IDR-L","p");
   entry->SetLineColor(1);
   entry->SetLineStyle(1);
   entry->SetLineWidth(1);

   ci = TColor::GetColor("#0000ff");
   entry->SetMarkerColor(ci);
   entry->SetMarkerStyle(21);
   entry->SetMarkerSize(0.7);
   entry->SetTextFont(62);
   entry=leg->AddEntry("Graph1","IDR-S","p");
   entry->SetLineColor(1);
   entry->SetLineStyle(1);
   entry->SetLineWidth(1);

   ci = TColor::GetColor("#ff0000");
   entry->SetMarkerColor(ci);
   entry->SetMarkerStyle(21);
   entry->SetMarkerSize(0.7);
   entry->SetTextFont(62);
   leg->Draw();
   c39->Modified();
   c39->cd();
   c39->SetSelected(c39);
}
