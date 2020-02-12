void IDR2EResolutionTheta()
{
//=========Macro generated from canvas: c138/c138
//=========  (Fri Jun 21 20:09:00 2019) by ROOT version6.08/06
   TCanvas *c138 = new TCanvas("c138", "c138",253,63,600,600);
   gStyle->SetOptFit(1);
   c138->Range(-0.3592143,-0.007054054,1.077643,0.03213514);
   c138->SetFillColor(10);
   c138->SetBorderMode(0);
   c138->SetBorderSize(2);
   c138->SetTickx(1);
   c138->SetTicky(1);
   c138->SetLeftMargin(0.25);
   c138->SetRightMargin(0.05);
   c138->SetTopMargin(0.08);
   c138->SetBottomMargin(0.18);
   c138->SetFrameLineWidth(3);
   c138->SetFrameBorderMode(0);
   c138->SetFrameLineWidth(3);
   c138->SetFrameBorderMode(0);
   
   Double_t Graph0_fx1005[20] = {
   0.025,
   0.075,
   0.125,
   0.175,
   0.225,
   0.275,
   0.325,
   0.375,
   0.425,
   0.475,
   0.525,
   0.575,
   0.625,
   0.675,
   0.725,
   0.775,
   0.825,
   0.875,
   0.925,
   0.975};
   Double_t Graph0_fy1005[20] = {
   0.01436877,
   0.01434315,
   0.01642551,
   0.01216559,
   0.01636629,
   0.01259626,
   0.01259713,
   0.01610485,
   0.01265653,
   0.01409793,
   0.01581615,
   0.01718309,
   0.01415207,
   0.0145691,
   0.01506894,
   0.01733973,
   0.01343478,
   0.01330418,
   0.01254635,
   0.01517327};
   Double_t Graph0_fex1005[20] = {
   0,
   0,
   0,
   0,
   0,
   0,
   0,
   0,
   0,
   0,
   0,
   0,
   0,
   0,
   0,
   0,
   0,
   0,
   0,
   0};
   Double_t Graph0_fey1005[20] = {
   0.000971617,
   0.00105771,
   0.00126976,
   0.0006534431,
   0.001378383,
   0.0006985201,
   0.0006079473,
   0.0009737086,
   0.0006481998,
   0.0006325877,
   0.0008505323,
   0.001130003,
   0.0005801011,
   0.0005914206,
   0.0004884464,
   0.0007575202,
   0.0004323424,
   0.0003231713,
   0.0002158403,
   0.0001932166};
   TGraphErrors *gre = new TGraphErrors(20,Graph0_fx1005,Graph0_fy1005,Graph0_fex1005,Graph0_fey1005);
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
   
   TH1F *Graph_Graph1005 = new TH1F("Graph_Graph1005","",100,0,1.07);
   Graph_Graph1005->SetMinimum(0);
   Graph_Graph1005->SetMaximum(0.029);
   Graph_Graph1005->SetDirectory(0);
   Graph_Graph1005->SetStats(0);
   Graph_Graph1005->SetLineWidth(3);
   Graph_Graph1005->SetMarkerStyle(21);
   Graph_Graph1005->SetMarkerSize(0.5);
   Graph_Graph1005->GetXaxis()->SetTitle("|cos#theta_{#gamma}|");
   Graph_Graph1005->GetXaxis()->SetRange(1,94);
   Graph_Graph1005->GetXaxis()->SetNdivisions(506);
   Graph_Graph1005->GetXaxis()->SetLabelFont(42);
   Graph_Graph1005->GetXaxis()->SetLabelOffset(0.015);
   Graph_Graph1005->GetXaxis()->SetLabelSize(0.06);
   Graph_Graph1005->GetXaxis()->SetTitleSize(0.07);
   Graph_Graph1005->GetXaxis()->SetTitleFont(42);
   Graph_Graph1005->GetYaxis()->SetTitle("Sigma of (E_{#gamma}-E_{#gamma}^{MC})/E_{#gamma}^{MC}");
   Graph_Graph1005->GetYaxis()->SetNdivisions(506);
   Graph_Graph1005->GetYaxis()->SetLabelFont(42);
   Graph_Graph1005->GetYaxis()->SetLabelOffset(0.015);
   Graph_Graph1005->GetYaxis()->SetLabelSize(0.05);
   Graph_Graph1005->GetYaxis()->SetTitleSize(0.07);
   Graph_Graph1005->GetYaxis()->SetTitleOffset(1.6);
   Graph_Graph1005->GetYaxis()->SetTitleFont(42);
   Graph_Graph1005->GetZaxis()->SetLabelFont(42);
   Graph_Graph1005->GetZaxis()->SetLabelOffset(0.015);
   Graph_Graph1005->GetZaxis()->SetLabelSize(0.06);
   Graph_Graph1005->GetZaxis()->SetTitleSize(0.07);
   Graph_Graph1005->GetZaxis()->SetTitleOffset(1.1);
   Graph_Graph1005->GetZaxis()->SetTitleFont(42);
   gre->SetHistogram(Graph_Graph1005);
   
   gre->Draw("ap");
   
   Double_t Graph1_fx1006[20] = {
   0.025,
   0.075,
   0.125,
   0.175,
   0.225,
   0.275,
   0.325,
   0.375,
   0.425,
   0.475,
   0.525,
   0.575,
   0.625,
   0.675,
   0.725,
   0.775,
   0.825,
   0.875,
   0.925,
   0.975};
   Double_t Graph1_fy1006[20] = {
   0.003855743,
   0.003118154,
   0.003747653,
   0.003910964,
   0.003656302,
   0.003495468,
   0.003450903,
   0.003410321,
   0.003384626,
   0.003968177,
   0.003187305,
   0.00339671,
   0.003378146,
   0.003249774,
   0.003704608,
   0.003740125,
   0.003943416,
   0.004844548,
   0.00642728,
   0.01100979};
   Double_t Graph1_fex1006[20] = {
   0,
   0,
   0,
   0,
   0,
   0,
   0,
   0,
   0,
   0,
   0,
   0,
   0,
   0,
   0,
   0,
   0,
   0,
   0,
   0};
   Double_t Graph1_fey1006[20] = {
   0.0001939842,
   0.0001862003,
   0.0002741572,
   0.0002521843,
   0.000320866,
   0.0002295685,
   0.0002012545,
   0.0001820449,
   0.0001814405,
   0.0002260525,
   0.0001790818,
   0.0002046025,
   0.0001703442,
   0.0001475198,
   0.0001459886,
   0.0001497147,
   0.0001376429,
   0.0001407317,
   0.0001863456,
   0.0002244962};
   gre = new TGraphErrors(20,Graph1_fx1006,Graph1_fy1006,Graph1_fex1006,Graph1_fey1006);
   gre->SetName("Graph1");
   gre->SetTitle("Graph");
   gre->SetFillColor(1);
   gre->SetLineColor(4);
   gre->SetLineWidth(3);
   gre->SetMarkerColor(4);
   gre->SetMarkerStyle(22);
   gre->SetMarkerSize(0.9);
   
   TH1F *Graph_Graph1006 = new TH1F("Graph_Graph1006","Graph",100,0,1.07);
   Graph_Graph1006->SetMinimum(0);
   Graph_Graph1006->SetMaximum(0.01206452);
   Graph_Graph1006->SetDirectory(0);
   Graph_Graph1006->SetStats(0);
   Graph_Graph1006->SetLineWidth(3);
   Graph_Graph1006->SetMarkerStyle(21);
   Graph_Graph1006->SetMarkerSize(0.5);
   Graph_Graph1006->GetXaxis()->SetNdivisions(506);
   Graph_Graph1006->GetXaxis()->SetLabelFont(42);
   Graph_Graph1006->GetXaxis()->SetLabelOffset(0.015);
   Graph_Graph1006->GetXaxis()->SetLabelSize(0.06);
   Graph_Graph1006->GetXaxis()->SetTitleSize(0.07);
   Graph_Graph1006->GetXaxis()->SetTitleFont(42);
   Graph_Graph1006->GetYaxis()->SetNdivisions(506);
   Graph_Graph1006->GetYaxis()->SetLabelFont(42);
   Graph_Graph1006->GetYaxis()->SetLabelOffset(0.015);
   Graph_Graph1006->GetYaxis()->SetLabelSize(0.06);
   Graph_Graph1006->GetYaxis()->SetTitleSize(0.07);
   Graph_Graph1006->GetYaxis()->SetTitleOffset(1.1);
   Graph_Graph1006->GetYaxis()->SetTitleFont(42);
   Graph_Graph1006->GetZaxis()->SetLabelFont(42);
   Graph_Graph1006->GetZaxis()->SetLabelOffset(0.015);
   Graph_Graph1006->GetZaxis()->SetLabelSize(0.06);
   Graph_Graph1006->GetZaxis()->SetTitleSize(0.07);
   Graph_Graph1006->GetZaxis()->SetTitleOffset(1.1);
   Graph_Graph1006->GetZaxis()->SetTitleFont(42);
   gre->SetHistogram(Graph_Graph1006);
   
   gre->Draw("p ");
   
   Double_t Graph2_fx1007[20] = {
   0.025,
   0.075,
   0.125,
   0.175,
   0.225,
   0.275,
   0.325,
   0.375,
   0.425,
   0.475,
   0.525,
   0.575,
   0.625,
   0.675,
   0.725,
   0.775,
   0.825,
   0.875,
   0.925,
   0.975};
   Double_t Graph2_fy1007[20] = {
   0.004108667,
   0.004253545,
   0.00486847,
   0.004049633,
   0.004902859,
   0.00393315,
   0.004664733,
   0.003934728,
   0.00458146,
   0.004241478,
   0.00414003,
   0.004284054,
   0.00415284,
   0.004084109,
   0.003720545,
   0.004001196,
   0.004743432,
   0.004979978,
   0.005887735,
   0.009922989};
   Double_t Graph2_fex1007[20] = {
   0,
   0,
   0,
   0,
   0,
   0,
   0,
   0,
   0,
   0,
   0,
   0,
   0,
   0,
   0,
   0,
   0,
   0,
   0,
   0};
   Double_t Graph2_fey1007[20] = {
   0.0002621316,
   0.0002844648,
   0.0003044384,
   0.0002415852,
   0.0002899099,
   0.0002603132,
   0.0002459193,
   0.0002032435,
   0.0002863458,
   0.0002309819,
   0.0003079198,
   0.0001873099,
   0.0002155822,
   0.0001817101,
   0.0001428114,
   0.0001434379,
   0.0001787935,
   0.0001466095,
   0.0001532449,
   0.0002088892};
   gre = new TGraphErrors(20,Graph2_fx1007,Graph2_fy1007,Graph2_fex1007,Graph2_fey1007);
   gre->SetName("Graph2");
   gre->SetTitle("Graph");
   gre->SetFillColor(1);
   gre->SetLineColor(2);
   gre->SetLineWidth(3);
   gre->SetMarkerColor(2);
   gre->SetMarkerStyle(22);
   gre->SetMarkerSize(0.9);
   
   TH1F *Graph_Graph1007 = new TH1F("Graph_Graph1007","Graph",100,0,1.07);
   Graph_Graph1007->SetMinimum(0);
   Graph_Graph1007->SetMaximum(0.01078729);
   Graph_Graph1007->SetDirectory(0);
   Graph_Graph1007->SetStats(0);
   Graph_Graph1007->SetLineWidth(3);
   Graph_Graph1007->SetMarkerStyle(21);
   Graph_Graph1007->SetMarkerSize(0.5);
   Graph_Graph1007->GetXaxis()->SetNdivisions(506);
   Graph_Graph1007->GetXaxis()->SetLabelFont(42);
   Graph_Graph1007->GetXaxis()->SetLabelOffset(0.015);
   Graph_Graph1007->GetXaxis()->SetLabelSize(0.06);
   Graph_Graph1007->GetXaxis()->SetTitleSize(0.07);
   Graph_Graph1007->GetXaxis()->SetTitleFont(42);
   Graph_Graph1007->GetYaxis()->SetNdivisions(506);
   Graph_Graph1007->GetYaxis()->SetLabelFont(42);
   Graph_Graph1007->GetYaxis()->SetLabelOffset(0.015);
   Graph_Graph1007->GetYaxis()->SetLabelSize(0.06);
   Graph_Graph1007->GetYaxis()->SetTitleSize(0.07);
   Graph_Graph1007->GetYaxis()->SetTitleOffset(1.1);
   Graph_Graph1007->GetYaxis()->SetTitleFont(42);
   Graph_Graph1007->GetZaxis()->SetLabelFont(42);
   Graph_Graph1007->GetZaxis()->SetLabelOffset(0.015);
   Graph_Graph1007->GetZaxis()->SetLabelSize(0.06);
   Graph_Graph1007->GetZaxis()->SetTitleSize(0.07);
   Graph_Graph1007->GetZaxis()->SetTitleOffset(1.1);
   Graph_Graph1007->GetZaxis()->SetTitleFont(42);
   gre->SetHistogram(Graph_Graph1007);
   
   gre->Draw("p ");
   
   Double_t Graph3_fx1008[20] = {
   0.025,
   0.075,
   0.125,
   0.175,
   0.225,
   0.275,
   0.325,
   0.375,
   0.425,
   0.475,
   0.525,
   0.575,
   0.625,
   0.675,
   0.725,
   0.775,
   0.825,
   0.875,
   0.925,
   0.975};
   Double_t Graph3_fy1008[20] = {
   0.01465879,
   0.01174474,
   0.01525813,
   0.01537851,
   0.0140628,
   0.01619439,
   0.01205933,
   0.0139535,
   0.01541984,
   0.01466583,
   0.01327033,
   0.01553385,
   0.01468866,
   0.01772447,
   0.01424565,
   0.01432316,
   0.01746091,
   0.01319615,
   0.01238177,
   0.01520541};
   Double_t Graph3_fex1008[20] = {
   0,
   0,
   0,
   0,
   0,
   0,
   0,
   0,
   0,
   0,
   0,
   0,
   0,
   0,
   0,
   0,
   0,
   0,
   0,
   0};
   Double_t Graph3_fey1008[20] = {
   0.001131159,
   0.0009351769,
   0.001036975,
   0.0009955672,
   0.000875238,
   0.001278337,
   0.0007504886,
   0.0007491076,
   0.0009180511,
   0.0007001309,
   0.0006553598,
   0.0007785212,
   0.0006297444,
   0.0009734819,
   0.0005462553,
   0.0004644085,
   0.0006557981,
   0.0003354242,
   0.000235772,
   0.0001982283};
   gre = new TGraphErrors(20,Graph3_fx1008,Graph3_fy1008,Graph3_fex1008,Graph3_fey1008);
   gre->SetName("Graph3");
   gre->SetTitle("Graph");
   gre->SetFillColor(1);

   ci = TColor::GetColor("#ff3399");
   gre->SetLineColor(ci);
   gre->SetLineWidth(3);

   ci = TColor::GetColor("#ff3399");
   gre->SetMarkerColor(ci);
   gre->SetMarkerStyle(21);
   gre->SetMarkerSize(0.7);
   
   TH1F *Graph_Graph1008 = new TH1F("Graph_Graph1008","Graph",100,0,1.07);
   Graph_Graph1008->SetMinimum(0.01002073);
   Graph_Graph1008->SetMaximum(0.01948679);
   Graph_Graph1008->SetDirectory(0);
   Graph_Graph1008->SetStats(0);
   Graph_Graph1008->SetLineWidth(3);
   Graph_Graph1008->SetMarkerStyle(21);
   Graph_Graph1008->SetMarkerSize(0.5);
   Graph_Graph1008->GetXaxis()->SetNdivisions(506);
   Graph_Graph1008->GetXaxis()->SetLabelFont(42);
   Graph_Graph1008->GetXaxis()->SetLabelOffset(0.015);
   Graph_Graph1008->GetXaxis()->SetLabelSize(0.06);
   Graph_Graph1008->GetXaxis()->SetTitleSize(0.07);
   Graph_Graph1008->GetXaxis()->SetTitleFont(42);
   Graph_Graph1008->GetYaxis()->SetNdivisions(506);
   Graph_Graph1008->GetYaxis()->SetLabelFont(42);
   Graph_Graph1008->GetYaxis()->SetLabelOffset(0.015);
   Graph_Graph1008->GetYaxis()->SetLabelSize(0.06);
   Graph_Graph1008->GetYaxis()->SetTitleSize(0.07);
   Graph_Graph1008->GetYaxis()->SetTitleOffset(1.1);
   Graph_Graph1008->GetYaxis()->SetTitleFont(42);
   Graph_Graph1008->GetZaxis()->SetLabelFont(42);
   Graph_Graph1008->GetZaxis()->SetLabelOffset(0.015);
   Graph_Graph1008->GetZaxis()->SetLabelSize(0.06);
   Graph_Graph1008->GetZaxis()->SetTitleSize(0.07);
   Graph_Graph1008->GetZaxis()->SetTitleOffset(1.1);
   Graph_Graph1008->GetZaxis()->SetTitleFont(42);
   gre->SetHistogram(Graph_Graph1008);
   
   gre->Draw("p ");
   
   TLegend *leg = new TLegend(0.55,0.72,0.94,0.9,NULL,"brNDC");
   leg->SetBorderSize(0);
   leg->SetTextFont(62);
   leg->SetTextSize(0.03787879);
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
   entry=leg->AddEntry("Graph3","PFO IDR-S","p");
   entry->SetLineColor(1);
   entry->SetLineStyle(1);
   entry->SetLineWidth(1);

   ci = TColor::GetColor("#ff3399");
   entry->SetMarkerColor(ci);
   entry->SetMarkerStyle(21);
   entry->SetMarkerSize(0.7);
   entry->SetTextFont(62);
   entry=leg->AddEntry("Graph1","Ang. Method IDR-L","p");
   entry->SetLineColor(1);
   entry->SetLineStyle(1);
   entry->SetLineWidth(1);
   entry->SetMarkerColor(4);
   entry->SetMarkerStyle(22);
   entry->SetMarkerSize(0.9);
   entry->SetTextFont(62);
   entry=leg->AddEntry("Graph2","Ang. Method IDR-S","p");
   entry->SetLineColor(1);
   entry->SetLineStyle(1);
   entry->SetLineWidth(1);
   entry->SetMarkerColor(2);
   entry->SetMarkerStyle(22);
   entry->SetMarkerSize(0.9);
   entry->SetTextFont(62);
   leg->Draw();
   TLatex *   tex = new TLatex(0.02,0.027,"ILD preliminary");
   tex->SetLineWidth(2);
   tex->Draw();
   c138->Modified();
   c138->cd();
   c138->SetSelected(c138);
}
