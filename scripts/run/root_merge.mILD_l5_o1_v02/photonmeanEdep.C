void photonmeanEdep()
{
//=========Macro generated from canvas: c38/c38
//=========  (Wed Apr 17 17:50:53 2019) by ROOT version6.08/06
   TCanvas *c38 = new TCanvas("c38", "c38",10,32,700,500);
   gStyle->SetOptFit(1);
   c38->Range(23.62,-5.252608,287.62,-1.198554);
   c38->SetFillColor(10);
   c38->SetBorderMode(0);
   c38->SetBorderSize(2);
   c38->SetLogy();
   c38->SetTickx(1);
   c38->SetTicky(1);
   c38->SetLeftMargin(0.17);
   c38->SetRightMargin(0.08);
   c38->SetTopMargin(0.08);
   c38->SetBottomMargin(0.18);
   c38->SetFrameLineWidth(3);
   c38->SetFrameBorderMode(0);
   c38->SetFrameLineWidth(3);
   c38->SetFrameBorderMode(0);
   
   Double_t Graph0_fx1001[7] = {
   85,
   140,
   170,
   190,
   210,
   230,
   250};
   Double_t Graph0_fy1001[7] = {
   0.01045295,
   0.01046721,
   0.01646028,
   0.01709709,
   0.01833177,
   0.01765327,
   0.01646045};
   Double_t Graph0_fex1001[7] = {
   0,
   0,
   0,
   0,
   0,
   0,
   0};
   Double_t Graph0_fey1001[7] = {
   0.003514386,
   0.002116259,
   0.001185067,
   0.0008339914,
   0.0004545079,
   0.0002183409,
   0.0001886068};
   TGraphErrors *gre = new TGraphErrors(7,Graph0_fx1001,Graph0_fy1001,Graph0_fex1001,Graph0_fey1001);
   gre->SetName("Graph0");
   gre->SetTitle("Graph");
   gre->SetFillColor(1);

   Int_t ci;      // for color index setting
   TColor *color; // for color definition with alpha
   ci = TColor::GetColor("#00ccff");
   gre->SetLineColor(ci);
   gre->SetLineWidth(3);

   ci = TColor::GetColor("#00ccff");
   gre->SetMarkerColor(ci);
   gre->SetMarkerStyle(3);
   gre->SetMarkerSize(0.5);
   
   TH1F *Graph_Graph1001 = new TH1F("Graph_Graph1001","Graph",100,68.5,266.5);
   Graph_Graph1001->SetMinimum(3e-05);
   Graph_Graph1001->SetMaximum(0.03);
   Graph_Graph1001->SetDirectory(0);
   Graph_Graph1001->SetStats(0);
   Graph_Graph1001->SetLineWidth(3);
   Graph_Graph1001->SetMarkerStyle(21);
   Graph_Graph1001->SetMarkerSize(0.5);
   Graph_Graph1001->GetXaxis()->SetNdivisions(506);
   Graph_Graph1001->GetXaxis()->SetLabelFont(42);
   Graph_Graph1001->GetXaxis()->SetLabelOffset(0.015);
   Graph_Graph1001->GetXaxis()->SetLabelSize(0.06);
   Graph_Graph1001->GetXaxis()->SetTitleSize(0.07);
   Graph_Graph1001->GetXaxis()->SetTitleFont(42);
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
   
   Double_t Graph1_fx1002[7] = {
   85,
   140,
   170,
   190,
   210,
   230,
   250};
   Double_t Graph1_fy1002[7] = {
   -0.002607345,
   0.0008573781,
   0.0001897275,
   0.0005294596,
   0.0003999034,
   0.0003967456,
   0.0004451157};
   Double_t Graph1_fex1002[7] = {
   0,
   0,
   0,
   0,
   0,
   0,
   0};
   Double_t Graph1_fey1002[7] = {
   0.03246369,
   0.000732562,
   0.0003849562,
   0.0002721179,
   0.0001532565,
   6.928825e-05,
   7.393605e-05};
   gre = new TGraphErrors(7,Graph1_fx1002,Graph1_fy1002,Graph1_fex1002,Graph1_fey1002);
   gre->SetName("Graph1");
   gre->SetTitle("Graph");
   gre->SetFillColor(1);

   ci = TColor::GetColor("#0033ff");
   gre->SetLineColor(ci);
   gre->SetLineWidth(3);

   ci = TColor::GetColor("#0033ff");
   gre->SetMarkerColor(ci);
   gre->SetMarkerStyle(3);
   gre->SetMarkerSize(0.5);
   
   TH1F *Graph_Graph1002 = new TH1F("Graph_Graph1002","Graph",100,68.5,266.5);
   Graph_Graph1002->SetMinimum(0);
   Graph_Graph1002->SetMaximum(0.03634908);
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
   
   TPaveText *pt = new TPaveText(0.01,0.9393038,0.1159599,0.995,"blNDC");
   pt->SetName("title");
   pt->SetBorderSize(0);
   pt->SetFillColor(0);
   pt->SetLineWidth(3);
   TText *AText = pt->AddText("Graph");
   pt->Draw();
   c38->Modified();
   c38->cd();
   c38->SetSelected(c38);
}
