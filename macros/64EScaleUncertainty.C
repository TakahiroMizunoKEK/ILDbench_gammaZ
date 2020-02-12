void 64EScaleUncertainty()
{
//=========Macro generated from canvas: c138/c138
//=========  (Thu Jun 27 17:53:46 2019) by ROOT version6.08/06
   TCanvas *c138 = new TCanvas("c138", "c138",0,22,600,600);
   gStyle->SetOptFit(1);
   c138->Range(-0.3592143,-0.011,1.077643,0.039);
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
   
   Double_t Graph0_fx1001[20] = {
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
   Double_t Graph0_fy1001[20] = {
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
   Double_t Graph0_fex1001[20] = {
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
   Double_t Graph0_fey1001[20] = {
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
   TGraphErrors *gre = new TGraphErrors(20,Graph0_fx1001,Graph0_fy1001,Graph0_fex1001,Graph0_fey1001);
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
   
   TH1F *Graph_Graph1001 = new TH1F("Graph_Graph1001","",100,0,1.07);
   Graph_Graph1001->SetMinimum(-0.002);
   Graph_Graph1001->SetMaximum(0.035);
   Graph_Graph1001->SetDirectory(0);
   Graph_Graph1001->SetStats(0);
   Graph_Graph1001->SetLineWidth(3);
   Graph_Graph1001->SetMarkerStyle(21);
   Graph_Graph1001->SetMarkerSize(0.5);
   Graph_Graph1001->GetXaxis()->SetTitle("|cos#theta_{#gamma}|");
   Graph_Graph1001->GetXaxis()->SetRange(1,94);
   Graph_Graph1001->GetXaxis()->SetNdivisions(506);
   Graph_Graph1001->GetXaxis()->SetLabelFont(42);
   Graph_Graph1001->GetXaxis()->SetLabelOffset(0.015);
   Graph_Graph1001->GetXaxis()->SetLabelSize(0.06);
   Graph_Graph1001->GetXaxis()->SetTitleSize(0.07);
   Graph_Graph1001->GetXaxis()->SetTitleFont(42);
   Graph_Graph1001->GetYaxis()->SetTitle("Sigma of (E_{#gamma}-E_{#gamma}^{MC})/E_{#gamma}^{MC}");
   Graph_Graph1001->GetYaxis()->SetNdivisions(506);
   Graph_Graph1001->GetYaxis()->SetLabelFont(42);
   Graph_Graph1001->GetYaxis()->SetLabelOffset(0.015);
   Graph_Graph1001->GetYaxis()->SetLabelSize(0.05);
   Graph_Graph1001->GetYaxis()->SetTitleSize(0.07);
   Graph_Graph1001->GetYaxis()->SetTitleOffset(1.6);
   Graph_Graph1001->GetYaxis()->SetTitleFont(42);
   Graph_Graph1001->GetZaxis()->SetLabelFont(42);
   Graph_Graph1001->GetZaxis()->SetLabelOffset(0.015);
   Graph_Graph1001->GetZaxis()->SetLabelSize(0.06);
   Graph_Graph1001->GetZaxis()->SetTitleSize(0.07);
   Graph_Graph1001->GetZaxis()->SetTitleOffset(1.1);
   Graph_Graph1001->GetZaxis()->SetTitleFont(42);
   gre->SetHistogram(Graph_Graph1001);
   
   gre->Draw("ap");
   
   Double_t Graph1_fx1002[20] = {
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
   Double_t Graph1_fy1002[20] = {
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
   Double_t Graph1_fex1002[20] = {
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
   Double_t Graph1_fey1002[20] = {
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
   gre = new TGraphErrors(20,Graph1_fx1002,Graph1_fy1002,Graph1_fex1002,Graph1_fey1002);
   gre->SetName("Graph1");
   gre->SetTitle("Graph");
   gre->SetFillColor(1);
   gre->SetLineColor(4);
   gre->SetLineWidth(3);
   gre->SetMarkerColor(4);
   gre->SetMarkerStyle(22);
   gre->SetMarkerSize(0.9);
   
   TH1F *Graph_Graph1002 = new TH1F("Graph_Graph1002","Graph",100,0,1.07);
   Graph_Graph1002->SetMinimum(0);
   Graph_Graph1002->SetMaximum(0.01206452);
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
   
   Double_t Graph2_fx1003[20] = {
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
   Double_t Graph2_fy1003[20] = {
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
   Double_t Graph2_fex1003[20] = {
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
   Double_t Graph2_fey1003[20] = {
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
   gre = new TGraphErrors(20,Graph2_fx1003,Graph2_fy1003,Graph2_fex1003,Graph2_fey1003);
   gre->SetName("Graph2");
   gre->SetTitle("Graph");
   gre->SetFillColor(1);
   gre->SetLineColor(2);
   gre->SetLineWidth(3);
   gre->SetMarkerColor(2);
   gre->SetMarkerStyle(23);
   gre->SetMarkerSize(0.9);
   
   TH1F *Graph_Graph1003 = new TH1F("Graph_Graph1003","Graph",100,0,1.07);
   Graph_Graph1003->SetMinimum(0);
   Graph_Graph1003->SetMaximum(0.01078729);
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
   
   Double_t Graph3_fx1004[20] = {
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
   Double_t Graph3_fy1004[20] = {
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
   Double_t Graph3_fex1004[20] = {
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
   Double_t Graph3_fey1004[20] = {
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
   gre = new TGraphErrors(20,Graph3_fx1004,Graph3_fy1004,Graph3_fex1004,Graph3_fey1004);
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
   
   TH1F *Graph_Graph1004 = new TH1F("Graph_Graph1004","Graph",100,0,1.07);
   Graph_Graph1004->SetMinimum(0.01002073);
   Graph_Graph1004->SetMaximum(0.01948679);
   Graph_Graph1004->SetDirectory(0);
   Graph_Graph1004->SetStats(0);
   Graph_Graph1004->SetLineWidth(3);
   Graph_Graph1004->SetMarkerStyle(21);
   Graph_Graph1004->SetMarkerSize(0.5);
   Graph_Graph1004->GetXaxis()->SetNdivisions(506);
   Graph_Graph1004->GetXaxis()->SetLabelFont(42);
   Graph_Graph1004->GetXaxis()->SetLabelOffset(0.015);
   Graph_Graph1004->GetXaxis()->SetLabelSize(0.06);
   Graph_Graph1004->GetXaxis()->SetTitleSize(0.07);
   Graph_Graph1004->GetXaxis()->SetTitleFont(42);
   Graph_Graph1004->GetYaxis()->SetNdivisions(506);
   Graph_Graph1004->GetYaxis()->SetLabelFont(42);
   Graph_Graph1004->GetYaxis()->SetLabelOffset(0.015);
   Graph_Graph1004->GetYaxis()->SetLabelSize(0.06);
   Graph_Graph1004->GetYaxis()->SetTitleSize(0.07);
   Graph_Graph1004->GetYaxis()->SetTitleOffset(1.1);
   Graph_Graph1004->GetYaxis()->SetTitleFont(42);
   Graph_Graph1004->GetZaxis()->SetLabelFont(42);
   Graph_Graph1004->GetZaxis()->SetLabelOffset(0.015);
   Graph_Graph1004->GetZaxis()->SetLabelSize(0.06);
   Graph_Graph1004->GetZaxis()->SetTitleSize(0.07);
   Graph_Graph1004->GetZaxis()->SetTitleOffset(1.1);
   Graph_Graph1004->GetZaxis()->SetTitleFont(42);
   gre->SetHistogram(Graph_Graph1004);
   
   gre->Draw("p ");
   
   Double_t Graph4_fx1005[20] = {
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
   Double_t Graph4_fy1005[20] = {
   0.001380723,
   0.0004610976,
   0.0009819027,
   0.0009971072,
   0.001301084,
   0.0006957814,
   0.0006957416,
   0.000432439,
   0.001019509,
   0.0005964017,
   0.0009274795,
   0.0007930548,
   0.0009556215,
   0.0009399268,
   0.000918556,
   0.0007125626,
   0.001107447,
   0.001180272,
   0.001034681,
   0.001854646};
   Double_t Graph4_fex1005[20] = {
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
   Double_t Graph4_fey1005[20] = {
   0.0001950974,
   4.546051e-05,
   0.000123191,
   0.0001564869,
   0.0002748586,
   6.742164e-05,
   7.363329e-05,
   4.341724e-05,
   0.0001240218,
   6.441121e-05,
   7.565687e-05,
   6.954507e-05,
   6.635396e-05,
   6.660033e-05,
   5.339452e-05,
   4.633759e-05,
   6.340907e-05,
   6.082779e-05,
   4.361439e-05,
   5.40897e-05};
   gre = new TGraphErrors(20,Graph4_fx1005,Graph4_fy1005,Graph4_fex1005,Graph4_fey1005);
   gre->SetName("Graph4");
   gre->SetTitle("Graph");
   gre->SetFillColor(1);

   ci = TColor::GetColor("#009966");
   gre->SetLineColor(ci);
   gre->SetLineWidth(3);

   ci = TColor::GetColor("#009966");
   gre->SetMarkerColor(ci);
   gre->SetMarkerStyle(22);
   gre->SetMarkerSize(0.9);
   
   TH1F *Graph_Graph1005 = new TH1F("Graph_Graph1005","Graph",100,0,1.07);
   Graph_Graph1005->SetMinimum(0);
   Graph_Graph1005->SetMaximum(0.002060707);
   Graph_Graph1005->SetDirectory(0);
   Graph_Graph1005->SetStats(0);
   Graph_Graph1005->SetLineWidth(3);
   Graph_Graph1005->SetMarkerStyle(21);
   Graph_Graph1005->SetMarkerSize(0.5);
   Graph_Graph1005->GetXaxis()->SetNdivisions(506);
   Graph_Graph1005->GetXaxis()->SetLabelFont(42);
   Graph_Graph1005->GetXaxis()->SetLabelOffset(0.015);
   Graph_Graph1005->GetXaxis()->SetLabelSize(0.06);
   Graph_Graph1005->GetXaxis()->SetTitleSize(0.07);
   Graph_Graph1005->GetXaxis()->SetTitleFont(42);
   Graph_Graph1005->GetYaxis()->SetNdivisions(506);
   Graph_Graph1005->GetYaxis()->SetLabelFont(42);
   Graph_Graph1005->GetYaxis()->SetLabelOffset(0.015);
   Graph_Graph1005->GetYaxis()->SetLabelSize(0.06);
   Graph_Graph1005->GetYaxis()->SetTitleSize(0.07);
   Graph_Graph1005->GetYaxis()->SetTitleOffset(1.1);
   Graph_Graph1005->GetYaxis()->SetTitleFont(42);
   Graph_Graph1005->GetZaxis()->SetLabelFont(42);
   Graph_Graph1005->GetZaxis()->SetLabelOffset(0.015);
   Graph_Graph1005->GetZaxis()->SetLabelSize(0.06);
   Graph_Graph1005->GetZaxis()->SetTitleSize(0.07);
   Graph_Graph1005->GetZaxis()->SetTitleOffset(1.1);
   Graph_Graph1005->GetZaxis()->SetTitleFont(42);
   gre->SetHistogram(Graph_Graph1005);
   
   gre->Draw("p ");
   
   Double_t Graph5_fx1006[20] = {
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
   Double_t Graph5_fy1006[20] = {
   2.584389e-05,
   2.152794e-05,
   1.786326e-05,
   1.675691e-05,
   1.574641e-05,
   1.471642e-05,
   2.003985e-05,
   2.224899e-05,
   2.006409e-05,
   2.208073e-05,
   2.035184e-05,
   2.323617e-05,
   2.937379e-05,
   3.031884e-05,
   3.353898e-05,
   3.712872e-05,
   3.906792e-05,
   5.226506e-05,
   7.17957e-05,
   0.0001739868};
   Double_t Graph5_fex1006[20] = {
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
   Double_t Graph5_fey1006[20] = {
   3.035399e-06,
   1.581657e-06,
   1.919833e-06,
   1.514077e-06,
   1.421595e-06,
   1.121865e-06,
   1.369645e-06,
   1.69574e-06,
   2.151127e-06,
   1.60955e-06,
   1.431274e-06,
   2.031967e-06,
   2.10017e-06,
   1.532176e-06,
   1.918288e-06,
   2.099984e-06,
   1.849122e-06,
   2.050457e-06,
   2.562958e-06,
   3.756827e-06};
   gre = new TGraphErrors(20,Graph5_fx1006,Graph5_fy1006,Graph5_fex1006,Graph5_fey1006);
   gre->SetName("Graph5");
   gre->SetTitle("Graph");
   gre->SetFillColor(1);

   ci = TColor::GetColor("#33cc33");
   gre->SetLineColor(ci);
   gre->SetLineWidth(3);

   ci = TColor::GetColor("#33cc33");
   gre->SetMarkerColor(ci);
   gre->SetMarkerStyle(22);
   gre->SetMarkerSize(0.9);
   
   TH1F *Graph_Graph1006 = new TH1F("Graph_Graph1006","Graph",100,0,1.07);
   Graph_Graph1006->SetMinimum(0);
   Graph_Graph1006->SetMaximum(0.0001941585);
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
   
   Double_t Graph6_fx1007[20] = {
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
   Double_t Graph6_fy1007[20] = {
   0.0005208339,
   0.0006200478,
   0.001469745,
   0.001196155,
   0.001861899,
   0.0009100605,
   0.000712134,
   0.001562472,
   0.001049614,
   0.00126176,
   0.001072965,
   0.001339517,
   0.001016721,
   0.0008615261,
   0.0008914714,
   0.001054048,
   0.001056114,
   0.001337804,
   0.001268069,
   0.001887017};
   Double_t Graph6_fex1007[20] = {
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
   Double_t Graph6_fey1007[20] = {
   9.871122e-05,
   7.420639e-05,
   0.0001938701,
   0.0001636822,
   0.000215016,
   0.0001521734,
   7.511573e-05,
   0.0002212724,
   0.0001329748,
   0.0001603327,
   9.47277e-05,
   0.0001804929,
   0.0001087101,
   6.310707e-05,
   7.715191e-05,
   7.367793e-05,
   6.485749e-05,
   8.58241e-05,
   5.675939e-05,
   5.436927e-05};
   gre = new TGraphErrors(20,Graph6_fx1007,Graph6_fy1007,Graph6_fex1007,Graph6_fey1007);
   gre->SetName("Graph6");
   gre->SetTitle("Graph");
   gre->SetFillColor(1);

   ci = TColor::GetColor("#cc3300");
   gre->SetLineColor(ci);
   gre->SetLineWidth(3);

   ci = TColor::GetColor("#cc3300");
   gre->SetMarkerColor(ci);
   gre->SetMarkerStyle(23);
   gre->SetMarkerSize(0.9);
   
   TH1F *Graph_Graph1007 = new TH1F("Graph_Graph1007","Graph",100,0,1.07);
   Graph_Graph1007->SetMinimum(0);
   Graph_Graph1007->SetMaximum(0.002242395);
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
   
   Double_t Graph7_fx1008[20] = {
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
   Double_t Graph7_fy1008[20] = {
   1.836741e-05,
   1.818971e-05,
   2.15806e-05,
   2.030482e-05,
   2.400469e-05,
   1.770028e-05,
   1.785142e-05,
   1.910506e-05,
   2.675078e-05,
   1.909323e-05,
   2.151584e-05,
   3.183567e-05,
   2.748671e-05,
   3.181494e-05,
   3.664378e-05,
   4.228703e-05,
   3.886686e-05,
   4.650989e-05,
   6.862327e-05,
   0.0001664515};
   Double_t Graph7_fex1008[20] = {
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
   Double_t Graph7_fey1008[20] = {
   1.723951e-06,
   1.344211e-06,
   2.263913e-06,
   3.09257e-06,
   3.154808e-06,
   1.99525e-06,
   1.532476e-06,
   1.756727e-06,
   2.170687e-06,
   1.295864e-06,
   1.729781e-06,
   2.216793e-06,
   1.579955e-06,
   2.655701e-06,
   2.666665e-06,
   2.696815e-06,
   1.850727e-06,
   1.713206e-06,
   2.193145e-06,
   3.578947e-06};
   gre = new TGraphErrors(20,Graph7_fx1008,Graph7_fy1008,Graph7_fex1008,Graph7_fey1008);
   gre->SetName("Graph7");
   gre->SetTitle("Graph");
   gre->SetFillColor(1);

   ci = TColor::GetColor("#ff9900");
   gre->SetLineColor(ci);
   gre->SetLineWidth(3);

   ci = TColor::GetColor("#ff9900");
   gre->SetMarkerColor(ci);
   gre->SetMarkerStyle(23);
   gre->SetMarkerSize(0.9);
   
   TH1F *Graph_Graph1008 = new TH1F("Graph_Graph1008","Graph",100,0,1.07);
   Graph_Graph1008->SetMinimum(0);
   Graph_Graph1008->SetMaximum(0.000185463);
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
   
   TLegend *leg = new TLegend(0.55,0.66,0.9,0.9,NULL,"brNDC");
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
   entry->SetMarkerStyle(23);
   entry->SetMarkerSize(0.9);
   entry->SetTextFont(62);
   entry=leg->AddEntry("Graph4","IDR-L 1muE Cheated","p");
   entry->SetLineColor(1);
   entry->SetLineStyle(1);
   entry->SetLineWidth(1);

   ci = TColor::GetColor("#009966");
   entry->SetMarkerColor(ci);
   entry->SetMarkerStyle(22);
   entry->SetMarkerSize(0.9);
   entry->SetTextFont(62);
   entry=leg->AddEntry("Graph6","IDR-S 1muE Cheated","p");
   entry->SetLineColor(1);
   entry->SetLineStyle(1);
   entry->SetLineWidth(1);

   ci = TColor::GetColor("#cc3300");
   entry->SetMarkerColor(ci);
   entry->SetMarkerStyle(23);
   entry->SetMarkerSize(0.9);
   entry->SetTextFont(62);
   entry=leg->AddEntry("Graph5","IDR-L 2muE Cheated","p");
   entry->SetLineColor(1);
   entry->SetLineStyle(1);
   entry->SetLineWidth(1);

   ci = TColor::GetColor("#33cc33");
   entry->SetMarkerColor(ci);
   entry->SetMarkerStyle(22);
   entry->SetMarkerSize(0.9);
   entry->SetTextFont(62);
   entry=leg->AddEntry("Graph7","IDR-S 2muE Cheated","p");
   entry->SetLineColor(1);
   entry->SetLineStyle(1);
   entry->SetLineWidth(1);

   ci = TColor::GetColor("#ff9900");
   entry->SetMarkerColor(ci);
   entry->SetMarkerStyle(23);
   entry->SetMarkerSize(0.9);
   entry->SetTextFont(62);
   leg->Draw();
   TLatex *   tex = new TLatex(0.02,0.032,"ILD preliminary");
   tex->SetLineWidth(2);
   tex->Draw();
   c138->Modified();
   c138->cd();
   c138->SetSelected(c138);
}
