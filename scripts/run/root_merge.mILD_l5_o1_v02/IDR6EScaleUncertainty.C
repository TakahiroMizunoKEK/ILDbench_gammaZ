void IDR6EScaleUncertainty()
{
//=========Macro generated from canvas: c39/c39
//=========  (Wed May  1 00:20:52 2019) by ROOT version6.08/06
   TCanvas *c39 = new TCanvas("c39", "c39",331,31,600,600);
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
   
   Double_t Graph0_fx1001[7] = {
   85,
   140,
   170,
   190,
   210,
   230,
   250};
   Double_t Graph0_fy1001[7] = {
   196.7842,
   73.9585,
   54.79332,
   45.63903,
   30.31754,
   14.71736,
   12.98384};
   Double_t Graph0_fex1001[7] = {
   35,
   20,
   10,
   10,
   10,
   10,
   10};
   Double_t Graph0_fey1001[7] = {
   88.42283,
   7.229618,
   3.674659,
   2.655205,
   0.8854699,
   0.2062626,
   0.1904206};
   TGraphErrors *gre = new TGraphErrors(7,Graph0_fx1001,Graph0_fy1001,Graph0_fex1001,Graph0_fey1001);
   gre->SetName("Graph0");
   gre->SetTitle("");
   gre->SetFillColor(1);

   Int_t ci;      // for color index setting
   TColor *color; // for color definition with alpha
   ci = TColor::GetColor("#00ccff");
   gre->SetLineColor(ci);
   gre->SetLineWidth(3);

   ci = TColor::GetColor("#00ccff");
   gre->SetMarkerColor(ci);
   gre->SetMarkerStyle(21);
   gre->SetMarkerSize(0.7);
   
   TH1F *Graph_Graph1001 = new TH1F("Graph_Graph1001","",100,29,281);
   Graph_Graph1001->SetMinimum(0);
   Graph_Graph1001->SetMaximum(312.4484);
   Graph_Graph1001->SetDirectory(0);
   Graph_Graph1001->SetStats(0);
   Graph_Graph1001->SetLineWidth(3);
   Graph_Graph1001->SetMarkerStyle(21);
   Graph_Graph1001->SetMarkerSize(0.5);
   Graph_Graph1001->GetXaxis()->SetTitle("E_{#gamma} [GeV]");
   Graph_Graph1001->GetXaxis()->SetNdivisions(506);
   Graph_Graph1001->GetXaxis()->SetLabelFont(42);
   Graph_Graph1001->GetXaxis()->SetLabelOffset(0.015);
   Graph_Graph1001->GetXaxis()->SetLabelSize(0.06);
   Graph_Graph1001->GetXaxis()->SetTitleSize(0.07);
   Graph_Graph1001->GetXaxis()->SetTitleFont(42);
   Graph_Graph1001->GetYaxis()->SetTitle("E_{#gamma} Scale Uncertainty [MeV]");
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
   TLatex *   tex = new TLatex(150,270,"ILD preliminary");
   tex->SetLineWidth(2);
   tex->Draw();
   c39->Modified();
   c39->cd();
   c39->SetSelected(c39);
}
