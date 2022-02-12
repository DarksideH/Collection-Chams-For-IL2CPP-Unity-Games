int rgb = 1;
bool rF = true, gF, bF = true, rF_, gF_, bF_;
float redd = 255, greenn = 0, bluee = 255;
void performRGBChange() {
switch (rgb) {
 case 0: {
  if (gF) {
   greenn--; 
   if (!greenn) { gF = !gF;  rF_ = !rF_; }
  break; }
  
  if (redd < 255 && rF_) redd++;
  else { rgb++; redd = 255; rF = !rF; rF_ = !rF_; }
 break; } case 1: {
  if (bF) {
   bluee--; 
   if (!bluee) { bF = !bF; gF_ = !gF_; }
  break; }

  if (greenn < 255 && gF_) greenn++;
  else { rgb++; greenn = 255; gF = !gF; gF_ = !gF_; }
 break;} case 2: {
  if (rF) {
   redd--; 
   if (!redd) { rF = !rF; bF_ = !bF_; }
  break; }
  
  if (bluee < 255 && bF_) bluee++;
  else { rgb = 0; bluee = 255; bF = !bF; bF_ = !bF_; }
  }
 }
}
