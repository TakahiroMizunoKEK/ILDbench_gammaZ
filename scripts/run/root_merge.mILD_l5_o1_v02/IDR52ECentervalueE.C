void IDR52ECentervalueE()
{
//=========Macro generated from canvas: c38/c38
//=========  (Wed May  1 00:07:23 2019) by ROOT version6.08/06
   TCanvas *c38 = new TCanvas("c38", "c38",0,22,600,600);
   gStyle->SetOptFit(1);
   c38->Range(-43.72,-0.04189189,287.48,0.07972973);
   c38->SetFillColor(10);
   c38->SetBorderMode(0);
   c38->SetBorderSize(2);
   c38->SetTickx(1);
   c38->SetTicky(1);
   c38->SetLeftMargin(0.25);
   c38->SetRightMargin(0.05);
   c38->SetTopMargin(0.08);
   c38->SetBottomMargin(0.18);
   c38->SetFrameLineWidth(3);
   c38->SetFrameBorderMode(0);
   c38->SetFrameLineWidth(3);
   c38->SetFrameBorderMode(0);
   
   Double_t Graph0_fx1001[6] = {
   140,
   170,
   190,
   210,
   230,
   250};
   Double_t Graph0_fy1001[6] = {
   0.01268758,
   0.01726291,
   0.01787711,
   0.01723888,
   0.01778604,
   0.01547};
   Double_t Graph0_fex1001[6] = {
   20,
   10,
   10,
   10,
   10,
   10};
   Double_t Graph0_fey1001[6] = {
   0.002194272,
   0.001301529,
   0.001042532,
   0.0005611812,
   0.0002497679,
   0.000240566};
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
   
   TH1F *Graph_Graph1001 = new TH1F("Graph_Graph1001","",100,107,273);
   Graph_Graph1001->SetMinimum(-0.01);
   Graph_Graph1001->SetMaximum(0.04);
   Graph_Graph1001->SetDirectory(0);
   Graph_Graph1001->SetStats(0);
   Graph_Graph1001->SetLineWidth(3);
   Graph_Graph1001->SetMarkerStyle(21);
   Graph_Graph1001->SetMarkerSize(0.5);
   Graph_Graph1001->GetXaxis()->SetTitle("E_{#gamma} [GeV]");
   Graph_Graph1001->GetXaxis()->SetRange(5,96);
   Graph_Graph1001->GetXaxis()->SetNdivisions(506);
   Graph_Graph1001->GetXaxis()->SetLabelFont(42);
   Graph_Graph1001->GetXaxis()->SetLabelOffset(0.015);
   Graph_Graph1001->GetXaxis()->SetLabelSize(0.06);
   Graph_Graph1001->GetXaxis()->SetTitleSize(0.07);
   Graph_Graph1001->GetXaxis()->SetTitleFont(42);
   Graph_Graph1001->GetYaxis()->SetTitle("Mean of (E_{#gamma}-E_{#gamma}^{MC})/E_{#gamma}^{MC}");
   Graph_Graph1001->GetYaxis()->SetNdivisions(506);
   Graph_Graph1001->GetYaxis()->SetLabelFont(42);
   Graph_Graph1001->GetYaxis()->SetLabelOffset(0.015);
   Graph_Graph1001->GetYaxis()->SetLabelSize(0.06);
   Graph_Graph1001->GetYaxis()->SetTitleSize(0.07);
   Graph_Graph1001->GetYaxis()->SetTitleOffset(1.5);
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
   138,
   168,
   188,
   208,
   228,
   248};
   Double_t Graph1_fy1002[6] = {
   -0.001526252,
   -0.0007238168,
   0.001247054,
   0.000212391,
   0.0008806865,
   -0.0009457311};
   Double_t Graph1_fex1002[6] = {
   20,
   10,
   10,
   10,
   10,
   10};
   Double_t Graph1_fey1002[6] = {
   0.002582906,
   0.001310606,
   0.001022809,
   0.0005385803,
   0.0002418154,
   0.0002267286};
   gre = new TGraphErrors(6,Graph1_fx1002,Graph1_fy1002,Graph1_fex1002,Graph1_fey1002);
   gre->SetName("Graph1");
   gre->SetTitle("Graph");
   gre->SetFillColor(1);

   ci = TColor::GetColor("#33cc33");
   gre->SetLineColor(ci);
   gre->SetLineWidth(3);

   ci = TColor::GetColor("#33cc33");
   gre->SetMarkerColor(ci);
   gre->SetMarkerStyle(21);
   gre->SetMarkerSize(0.7);
   
   TH1F *Graph_Graph1002 = new TH1F("Graph_Graph1002","Graph",100,107,273);
   Graph_Graph1002->SetMinimum(-0.01);
   Graph_Graph1002->SetMaximum(0.04);
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
   
   Double_t Graph2_fx1003[6]= {
   140,
   170,
   190,
   210,
   230,
   250};
   Double_t Graph2_fy1003[6] = {
   -0.0001755291,
   0.0003993114,
   0.0004455643,
   0.0003110292,
   0.0003848006,
   0.0004020492};
   Double_t Graph2_fex1003[6] = {
   20,
   10,
   10,
   10,
   10,
   10};
   Double_t Graph2_fey1003[6] = {
   0.0006046565,
   0.0003333006,
   0.0002607915,
   0.00015211,
   6.769945e-05,
   7.031275e-05};
   gre = new TGraphErrors(6,Graph2_fx1003,Graph2_fy1003,Graph2_fex1003,Graph2_fey1003);
   gre->SetName("Graph2");
   gre->SetTitle("Graph");
   gre->SetFillColor(1);
   gre->SetLineColor(4);
   gre->SetLineWidth(3);
   gre->SetMarkerColor(4);
   gre->SetMarkerStyle(22);
   gre->SetMarkerSize(0.9);
   
   TH1F *Graph_Graph1003 = new TH1F("Graph_Graph1003","Graph",100,107,273);
   Graph_Graph1003->SetMinimum(0);
   Graph_Graph1003->SetMaximum(0.003327032);
   Graph_Graph1003->SetDirectory(0);
   Graph_Graph1003->SetStats(0);
   Graph_Graph1003->SetLineWidth(3);
   Graph_Graph1003->SetMarkerStyle(21);
   Graph_Graph1003->SetMarkerSize(0.5);
   Graph_Graph1003->GetXaxis()->SetNdivisions(506);
   Graph_Graph1003->GetXaxis()->SetLabelFont(42);
   Graph_Graph1003->GetXaxis()->SetLabelOffset(0.015);
   Graph_Graph1003->GetXaxis()->SetLabelSize(0.06);
   Graph_Graph1003->GetXaxis()->SetTitleSize(0.07);
   Graph_Graph1003->GetXaxis()->SetTitleFont(42);
   Graph_Graph1003->GetYaxis()->SetNdivisions(506);
   Graph_Graph1003->GetYaxis()->SetLabelFont(42);
   Graph_Graph1003->GetYaxis()->SetLabelOffset(0.015);
   Graph_Graph1003->GetYaxis()->SetLabelSize(0.06);
   Graph_Graph1003->GetYaxis()->SetTitleSize(0.07);
   Graph_Graph1003->GetYaxis()->SetTitleOffset(1.1);
   Graph_Graph1003->GetYaxis()->SetTitleFont(42);
   Graph_Graph1003->GetZaxis()->SetLabelFont(42);
   Graph_Graph1003->GetZaxis()->SetLabelOffset(0.015);
   Graph_Graph1003->GetZaxis()->SetLabelSize(0.06);
   Graph_Graph1003->GetZaxis()->SetTitleSize(0.07);
   Graph_Graph1003->GetZaxis()->SetTitleOffset(1.1);
   Graph_Graph1003->GetZaxis()->SetTitleFont(42);
   gre->SetHistogram(Graph_Graph1003);
   
   gre->Draw("p ");
   
   TLegend *leg = new TLegend(0.6,0.65,0.93,0.85,NULL,"brNDC");
   leg->SetBorderSize(0);
   leg->SetTextFont(62);
   leg->SetTextSize(0.03787879);
   leg->SetLineColor(1);
   leg->SetLineStyle(1);
   leg->SetLineWidth(3);
   leg->SetFillColor(0);
   leg->SetFillStyle(1001);
   TLegendEntry *entry=leg->AddEntry("Graph2","Ang. Method","p");
   entry->SetLineColor(1);
   entry->SetLineStyle(1);
   entry->SetLineWidth(1);
   entry->SetMarkerColor(4);
   entry->SetMarkerStyle(22);
   entry->SetMarkerSize(0.9);
   entry->SetTextFont(62);
   entry=leg->AddEntry("Graph0","PFO","p");
   entry->SetLineColor(1);
   entry->SetLineStyle(1);
   entry->SetLineWidth(1);

   ci = TColor::GetColor("#00ccff");
   entry->SetMarkerColor(ci);
   entry->SetMarkerStyle(21);
   entry->SetMarkerSize(0.7);
   entry->SetTextFont(62);
   entry=leg->AddEntry("Graph1","Calibrated PFO","p");
   entry->SetLineColor(1);
   entry->SetLineStyle(1);
   entry->SetLineWidth(1);

   ci = TColor::GetColor("#33cc33");
   entry->SetMarkerColor(ci);
   entry->SetMarkerStyle(21);
   entry->SetMarkerSize(0.7);
   entry->SetTextFont(62);
   leg->Draw();
   TLatex *   tex = new TLatex(190,0.036,"ILD preliminary");
   tex->SetLineWidth(2);
   tex->Draw();
   c38->Modified();
   c38->cd();
   c38->SetSelected(c38);
}
