void IDRFig17()
{
//=========Macro generated from canvas: c38/c38
//=========  (Wed Dec 11 09:25:39 2019) by ROOT version6.08/06
   TCanvas *c38 = new TCanvas("c38", "c38",7,43,600,556);
   gStyle->SetOptFit(1);
   c38->Range(62.25143,-0.00972973,275.1657,0.04432432);
   c38->SetFillColor(10);
   c38->SetBorderMode(0);
   c38->SetBorderSize(2);
   c38->SetTickx(1);
   c38->SetTicky(1);
   c38->SetLeftMargin(0.25);
   c38->SetRightMargin(0.05);
   c38->SetTopMargin(0.08);
   c38->SetBottomMargin(0.18);
   c38->SetFrameFillColor(0);
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
   0.02095078,
   0.015418,
   0.01701075,
   0.01604644,
   0.01551571,
   0.01127125};
   Double_t Graph0_fex1001[6] = {
   20,
   10,
   10,
   10,
   10,
   10};
   Double_t Graph0_fey1001[6] = {
   0.001917373,
   0.001011903,
   0.0009628979,
   0.000458107,
   0.0002142483,
   0.0001618174};
   TGraphErrors *gre = new TGraphErrors(6,Graph0_fx1001,Graph0_fy1001,Graph0_fex1001,Graph0_fey1001);
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
   
   TH1F *Graph_Graph_Graph10011001 = new TH1F("Graph_Graph_Graph10011001","",100,109,271);
   Graph_Graph_Graph10011001->SetMinimum(0);
   Graph_Graph_Graph10011001->SetMaximum(0.04);
   Graph_Graph_Graph10011001->SetDirectory(0);
   Graph_Graph_Graph10011001->SetStats(0);

   ci = TColor::GetColor("#000099");
   Graph_Graph_Graph10011001->SetLineColor(ci);
   Graph_Graph_Graph10011001->SetLineWidth(3);
   Graph_Graph_Graph10011001->SetMarkerStyle(21);
   Graph_Graph_Graph10011001->SetMarkerSize(0.5);
   Graph_Graph_Graph10011001->GetXaxis()->SetTitle("E_{#gamma} [GeV]");
   Graph_Graph_Graph10011001->GetXaxis()->SetRange(5,96);
   Graph_Graph_Graph10011001->GetXaxis()->SetNdivisions(506);
   Graph_Graph_Graph10011001->GetXaxis()->SetLabelFont(42);
   Graph_Graph_Graph10011001->GetXaxis()->SetLabelOffset(0.015);
   Graph_Graph_Graph10011001->GetXaxis()->SetLabelSize(0.06);
   Graph_Graph_Graph10011001->GetXaxis()->SetTitleSize(0.07);
   Graph_Graph_Graph10011001->GetXaxis()->SetTitleFont(42);
   Graph_Graph_Graph10011001->GetYaxis()->SetTitle("Sigma of (E_{#gamma}-E_{#gamma}^{MC})/E_{#gamma}^{MC}");
   Graph_Graph_Graph10011001->GetYaxis()->SetNdivisions(506);
   Graph_Graph_Graph10011001->GetYaxis()->SetLabelFont(42);
   Graph_Graph_Graph10011001->GetYaxis()->SetLabelOffset(0.015);
   Graph_Graph_Graph10011001->GetYaxis()->SetLabelSize(0.06);
   Graph_Graph_Graph10011001->GetYaxis()->SetTitleSize(0.07);
   Graph_Graph_Graph10011001->GetYaxis()->SetTitleOffset(1.5);
   Graph_Graph_Graph10011001->GetYaxis()->SetTitleFont(42);
   Graph_Graph_Graph10011001->GetZaxis()->SetLabelFont(42);
   Graph_Graph_Graph10011001->GetZaxis()->SetLabelOffset(0.015);
   Graph_Graph_Graph10011001->GetZaxis()->SetLabelSize(0.06);
   Graph_Graph_Graph10011001->GetZaxis()->SetTitleSize(0.07);
   Graph_Graph_Graph10011001->GetZaxis()->SetTitleOffset(1.1);
   Graph_Graph_Graph10011001->GetZaxis()->SetTitleFont(42);
   gre->SetHistogram(Graph_Graph_Graph10011001);
   
   gre->Draw("ap");
   TF1 *func11 = new TF1("func1","sqrt(pow((.17/(sqrt(x))),2.)+pow(.01,2.))",120,260);
   func11->SetLineColor(1);
   func11->SetFillStyle(0);
   func11->SetLineWidth(2);
   func11->SetLineStyle(2);
   func11->GetXaxis()->SetLabelFont(42);
   func11->GetXaxis()->SetLabelSize(0.035);
   func11->GetXaxis()->SetTitleSize(0.035);
   func11->GetXaxis()->SetTitleFont(42);
   func11->GetYaxis()->SetLabelFont(42);
   func11->GetYaxis()->SetLabelSize(0.035);
   func11->GetYaxis()->SetTitleSize(0.035);
   func11->GetYaxis()->SetTitleFont(42);
   func11->Draw("same PC");
   
   gre->Draw("same p");

   Double_t Graph1_fx1002[6] = {
   140,
   170,
   190,
   210,
   230,
   250};
   Double_t Graph1_fy1002[6] = {
   0.02159286,
   0.0190112,
   0.01783221,
   0.01716336,
   0.01617805,
   0.01223115};
   Double_t Graph1_fex1002[6] = {
   20,
   10,
   10,
   10,
   10,
   10};
   Double_t Graph1_fey1002[6] = {
   0.001998716,
   0.001449111,
   0.0009154304,
   0.0005510092,
   0.0002310348,
   0.0002084035};
   gre = new TGraphErrors(6,Graph1_fx1002,Graph1_fy1002,Graph1_fex1002,Graph1_fey1002);
   gre->SetName("Graph1");
   gre->SetTitle("Graph");
   gre->SetFillColor(1);

   ci = TColor::GetColor("#ff0099");
   gre->SetLineColor(ci);
   gre->SetLineWidth(3);

   ci = TColor::GetColor("#ff0099");
   gre->SetMarkerColor(ci);
   gre->SetMarkerStyle(21);
   gre->SetMarkerSize(0.7);
   
   TH1F *Graph_Graph_Graph10021002 = new TH1F("Graph_Graph_Graph10021002","Graph",100,109,271);
   Graph_Graph_Graph10021002->SetMinimum(0.01026948);
   Graph_Graph_Graph10021002->SetMaximum(0.0313087);
   Graph_Graph_Graph10021002->SetDirectory(0);
   Graph_Graph_Graph10021002->SetStats(0);

   ci = TColor::GetColor("#000099");
   Graph_Graph_Graph10021002->SetLineColor(ci);
   Graph_Graph_Graph10021002->SetLineWidth(3);
   Graph_Graph_Graph10021002->SetMarkerStyle(21);
   Graph_Graph_Graph10021002->SetMarkerSize(0.5);
   Graph_Graph_Graph10021002->GetXaxis()->SetNdivisions(506);
   Graph_Graph_Graph10021002->GetXaxis()->SetLabelFont(42);
   Graph_Graph_Graph10021002->GetXaxis()->SetLabelOffset(0.015);
   Graph_Graph_Graph10021002->GetXaxis()->SetLabelSize(0.06);
   Graph_Graph_Graph10021002->GetXaxis()->SetTitleSize(0.07);
   Graph_Graph_Graph10021002->GetXaxis()->SetTitleFont(42);
   Graph_Graph_Graph10021002->GetYaxis()->SetNdivisions(506);
   Graph_Graph_Graph10021002->GetYaxis()->SetLabelFont(42);
   Graph_Graph_Graph10021002->GetYaxis()->SetLabelOffset(0.015);
   Graph_Graph_Graph10021002->GetYaxis()->SetLabelSize(0.06);
   Graph_Graph_Graph10021002->GetYaxis()->SetTitleSize(0.07);
   Graph_Graph_Graph10021002->GetYaxis()->SetTitleOffset(1.1);
   Graph_Graph_Graph10021002->GetYaxis()->SetTitleFont(42);
   Graph_Graph_Graph10021002->GetZaxis()->SetLabelFont(42);
   Graph_Graph_Graph10021002->GetZaxis()->SetLabelOffset(0.015);
   Graph_Graph_Graph10021002->GetZaxis()->SetLabelSize(0.06);
   Graph_Graph_Graph10021002->GetZaxis()->SetTitleSize(0.07);
   Graph_Graph_Graph10021002->GetZaxis()->SetTitleOffset(1.1);
   Graph_Graph_Graph10021002->GetZaxis()->SetTitleFont(42);
   gre->SetHistogram(Graph_Graph_Graph10021002);
   
   gre->Draw("p ");
   
   Double_t Graph2_fx1003[6] = {
   140,
   170,
   190,
   210,
   230,
   250};
   Double_t Graph2_fy1003[6] = {
   0.004114753,
   0.003169459,
   0.00405704,
   0.004019376,
   0.004081805,
   0.004075123};
   Double_t Graph2_fex1003[6] = {
   20,
   10,
   10,
   10,
   10,
   10};
   Double_t Graph2_fey1003[6] = {
   0.0006745188,
   0.0002716344,
   0.0003093284,
   0.0001490444,
   6.753053e-05,
   6.877092e-05};
   gre = new TGraphErrors(6,Graph2_fx1003,Graph2_fy1003,Graph2_fex1003,Graph2_fey1003);
   gre->SetName("Graph2");
   gre->SetTitle("Graph");
   gre->SetFillColor(1);
   gre->SetLineColor(4);
   gre->SetLineWidth(3);
   gre->SetMarkerColor(4);
   gre->SetMarkerStyle(22);
   gre->SetMarkerSize(0.9);
   
   TH1F *Graph_Graph_Graph10031003 = new TH1F("Graph_Graph_Graph10031003","Graph",100,109,271);
   Graph_Graph_Graph10031003->SetMinimum(0);
   Graph_Graph_Graph10031003->SetMaximum(0.02893798);
   Graph_Graph_Graph10031003->SetDirectory(0);
   Graph_Graph_Graph10031003->SetStats(0);

   ci = TColor::GetColor("#000099");
   Graph_Graph_Graph10031003->SetLineColor(ci);
   Graph_Graph_Graph10031003->SetLineWidth(3);
   Graph_Graph_Graph10031003->SetMarkerStyle(21);
   Graph_Graph_Graph10031003->SetMarkerSize(0.5);
   Graph_Graph_Graph10031003->GetXaxis()->SetNdivisions(506);
   Graph_Graph_Graph10031003->GetXaxis()->SetLabelFont(42);
   Graph_Graph_Graph10031003->GetXaxis()->SetLabelOffset(0.015);
   Graph_Graph_Graph10031003->GetXaxis()->SetLabelSize(0.06);
   Graph_Graph_Graph10031003->GetXaxis()->SetTitleSize(0.07);
   Graph_Graph_Graph10031003->GetXaxis()->SetTitleFont(42);
   Graph_Graph_Graph10031003->GetYaxis()->SetNdivisions(506);
   Graph_Graph_Graph10031003->GetYaxis()->SetLabelFont(42);
   Graph_Graph_Graph10031003->GetYaxis()->SetLabelOffset(0.015);
   Graph_Graph_Graph10031003->GetYaxis()->SetLabelSize(0.06);
   Graph_Graph_Graph10031003->GetYaxis()->SetTitleSize(0.07);
   Graph_Graph_Graph10031003->GetYaxis()->SetTitleOffset(1.1);
   Graph_Graph_Graph10031003->GetYaxis()->SetTitleFont(42);
   Graph_Graph_Graph10031003->GetZaxis()->SetLabelFont(42);
   Graph_Graph_Graph10031003->GetZaxis()->SetLabelOffset(0.015);
   Graph_Graph_Graph10031003->GetZaxis()->SetLabelSize(0.06);
   Graph_Graph_Graph10031003->GetZaxis()->SetTitleSize(0.07);
   Graph_Graph_Graph10031003->GetZaxis()->SetTitleOffset(1.1);
   Graph_Graph_Graph10031003->GetZaxis()->SetTitleFont(42);
   gre->SetHistogram(Graph_Graph_Graph10031003);
   
   gre->Draw("p ");
   
   Double_t Graph3_fx1004[6] = {
   140,
   170,
   190,
   210,
   230,
   250};
   Double_t Graph3_fy1004[6] = {
   0.003531255,
   0.004232431,
   0.004750062,
   0.00480424,
   0.004848921,
   0.004600696};
   Double_t Graph3_fex1004[6] = {
   20,
   10,
   10,
   10,
   10,
   10};
   Double_t Graph3_fey1004[6] = {
   0.0003988992,
   0.0004470144,
   0.0003174949,
   0.0001774787,
   7.796862e-05,
   7.591487e-05};
   gre = new TGraphErrors(6,Graph3_fx1004,Graph3_fy1004,Graph3_fex1004,Graph3_fey1004);
   gre->SetName("Graph3");
   gre->SetTitle("Graph");
   gre->SetFillColor(1);
   gre->SetLineColor(2);
   gre->SetLineWidth(3);
   gre->SetMarkerColor(2);
   gre->SetMarkerStyle(22);
   gre->SetMarkerSize(0.9);
   
   TH1F *Graph_Graph_Graph10041004 = new TH1F("Graph_Graph_Graph10041004","Graph",100,109,271);
   Graph_Graph_Graph10041004->SetMinimum(0);
   Graph_Graph_Graph10041004->SetMaximum(0.01148682);
   Graph_Graph_Graph10041004->SetDirectory(0);
   Graph_Graph_Graph10041004->SetStats(0);

   ci = TColor::GetColor("#000099");
   Graph_Graph_Graph10041004->SetLineColor(ci);
   Graph_Graph_Graph10041004->SetLineWidth(3);
   Graph_Graph_Graph10041004->SetMarkerStyle(21);
   Graph_Graph_Graph10041004->SetMarkerSize(0.5);
   Graph_Graph_Graph10041004->GetXaxis()->SetNdivisions(506);
   Graph_Graph_Graph10041004->GetXaxis()->SetLabelFont(42);
   Graph_Graph_Graph10041004->GetXaxis()->SetLabelOffset(0.015);
   Graph_Graph_Graph10041004->GetXaxis()->SetLabelSize(0.06);
   Graph_Graph_Graph10041004->GetXaxis()->SetTitleSize(0.07);
   Graph_Graph_Graph10041004->GetXaxis()->SetTitleFont(42);
   Graph_Graph_Graph10041004->GetYaxis()->SetNdivisions(506);
   Graph_Graph_Graph10041004->GetYaxis()->SetLabelFont(42);
   Graph_Graph_Graph10041004->GetYaxis()->SetLabelOffset(0.015);
   Graph_Graph_Graph10041004->GetYaxis()->SetLabelSize(0.06);
   Graph_Graph_Graph10041004->GetYaxis()->SetTitleSize(0.07);
   Graph_Graph_Graph10041004->GetYaxis()->SetTitleOffset(1.1);
   Graph_Graph_Graph10041004->GetYaxis()->SetTitleFont(42);
   Graph_Graph_Graph10041004->GetZaxis()->SetLabelFont(42);
   Graph_Graph_Graph10041004->GetZaxis()->SetLabelOffset(0.015);
   Graph_Graph_Graph10041004->GetZaxis()->SetLabelSize(0.06);
   Graph_Graph_Graph10041004->GetZaxis()->SetTitleSize(0.07);
   Graph_Graph_Graph10041004->GetZaxis()->SetTitleOffset(1.1);
   Graph_Graph_Graph10041004->GetZaxis()->SetTitleFont(42);
   gre->SetHistogram(Graph_Graph_Graph10041004);
   
   gre->Draw("p ");
   
   TLegend *leg = new TLegend(0.55,0.63,0.81,0.81,NULL,"brNDC");
   leg->SetBorderSize(0);
   leg->SetTextFont(62);
   leg->SetTextSize(0.04);
   leg->SetLineColor(1);
   leg->SetLineStyle(1);
   leg->SetLineWidth(3);
   leg->SetFillColor(0);
   leg->SetFillStyle(1001);
   TLegendEntry *entry=leg->AddEntry("Graph0","PFO IDR-L","p");
   entry->SetLineColor(1);
   entry->SetLineStyle(1);
   entry->SetLineWidth(1);

   ci = TColor::GetColor("#00ccff");
   entry->SetMarkerColor(ci);
   entry->SetMarkerStyle(21);
   entry->SetMarkerSize(0.7);
   entry->SetTextFont(62);
   entry=leg->AddEntry("Graph1","PFO IDR-S","p");
   entry->SetLineColor(1);
   entry->SetLineStyle(1);
   entry->SetLineWidth(1);

   ci = TColor::GetColor("#ff0099");
   entry->SetMarkerColor(ci);
   entry->SetMarkerStyle(21);
   entry->SetMarkerSize(0.7);
   entry->SetTextFont(62);
   entry=leg->AddEntry("Graph2","Ang. Method IDR-L","p");
   entry->SetLineColor(1);
   entry->SetLineStyle(1);
   entry->SetLineWidth(1);
   entry->SetMarkerColor(4);
   entry->SetMarkerStyle(22);
   entry->SetMarkerSize(0.9);
   entry->SetTextFont(62);
   entry=leg->AddEntry("Graph3","Ang. Method IDR-S","p");
   entry->SetLineColor(1);
   entry->SetLineStyle(1);
   entry->SetLineWidth(1);
   entry->SetMarkerColor(2);
   entry->SetMarkerStyle(22);
   entry->SetMarkerSize(0.9);
   entry->SetTextFont(62);
   leg->Draw();
   
   TLatex *   tex = new TLatex(185,0.0353,"ILD preliminary");
   tex->SetLineWidth(2);
   tex->Draw();
   c38->Modified();
   c38->cd();
   c38->SetSelected(c38);
}
