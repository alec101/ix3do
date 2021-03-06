#include "ix3do.h"



UI::UI() {
  w1= w2= null;

}


UI::~UI() {
  delData();
}


void UI::delData() {
}








void UI::init() {


  /// fonts and font styles

  fnt1_10= ix.pr.loadFont("montserrat.fnt", 10);
  fnt1_12= ix.pr.loadFont("montserrat.fnt", 12);
  fnt1_15= ix.pr.loadFont("montserrat.fnt", 15);
  fnt1_20= ix.pr.loadFont("montserrat.fnt", 20);


  fnt2_12= ix.pr.loadFont("montserratSB.fnt", 12);
  fnt2_13= ix.pr.loadFont("montserratSB.fnt", 13);
  fnt2_14= ix.pr.loadFont("montserratSB.fnt", 14);
  fnt2_15= ix.pr.loadFont("montserratSB.fnt", 15);
  fnt2_16= ix.pr.loadFont("montserratSB.fnt", 16);
  fnt2_17= ix.pr.loadFont("montserratSB.fnt", 17);
  fnt2_18= ix.pr.loadFont("montserratSB.fnt", 18);
  fnt2_20= ix.pr.loadFont("montserratSB.fnt", 20);


  fntStyle1.selFont= fnt2_12;
  fntStyle1.color1.set(1, 1, 1, 1);
  fntStyle1.drawMode= 0x02; //0x01;
  fntStyle1.outlineSize= 1;
  fntStyle1.shadowPos= vec2(1.0, 1.0);

  fntStyle2.selFont= fnt2_17;
  fntStyle2.color1.set(1, 1, 1, 1);
  fntStyle2.drawMode= 0x01; //| 0x02;
  fntStyle2.outlineSize= 1;
  fntStyle2.shadowPos= vec2(1.5, 1.5);
  
  
  ix.pr.style= &fntStyle2;

  ixDefFontStyle.selFont= fntStyle2.selFont;

  /// colors ===============================================

  col=         vec4(0.10f, 0.10f, 0.20f, 0.90f);
  colHover=    vec4(0.75f, 0.75f, 0.15f, 0.90f);         // 0.95f, 0.85f, 0.01f, .9f  good yellow but not liking
  colBRD=      vec4(0.70f, 0.70f, 0.70f, 1.00f);
  colFocus=    vec4(0.15f, 0.75f, 0.15f, 0.90f);
  colBRDfocus= vec4(0.95f, 0.95f, 0.95f, 1.00f);


  col=         vec4(0.10f, 0.10f, 0.20f, 0.8f);
  colHover=    vec4(0.85f, 0.75f, 0.15f, 1.0f);          // 0.95f, 0.85f, 0.01f, .9f  good yellow but not liking
  colBRD=      vec4(0.70f, 0.70f, 0.70f, 1.0f);
  colFocus=    vec4(0.15f, 0.75f, 0.15f, 1.0f);
  colBRDfocus= vec4(0.95f, 0.95f, 0.95f, 1.0f);


    /// window sys style
  //winStyle.delData();   << should this call all structs delData???

  winStyle.window.useTexture= false;
  winStyle.scroll.colorArrows.set(1.0f, 1.0f, 1.0f, 1.0f);
  winStyle.scroll.colorDragbox.set(1.0f, 1.0f, 1.0f, 1.0f);
  winStyle.scroll.color= col;
  winStyle.scroll.colorHover= colHover;
  winStyle.scroll.colorFocus= colFocus;


  winStyle.window.useTitle= true;
  winStyle.title.useTexture= false;

  winStyle.title.color=         col;
  winStyle.title.colorHover=    colHover;
  winStyle.title.colorBRD=      colBRD;
  winStyle.title.colorFocus=    colFocus;
  winStyle.title.colorBRDfocus= colBRDfocus;
  
  winStyle.window.titleInside= true;
  winStyle.window.color= col;
  winStyle.window.colorBRD= colBRD;
  winStyle.window.colorHover= colHover;
  winStyle.window.colorFocus= colFocus;
  winStyle.window.colorBRDfocus= colBRDfocus;
  
  winStyle.button.color= col;
  winStyle.button.colorBRD= colBRD;
  winStyle.button.colorHover= colHover;
  winStyle.button.colorFocus= colFocus;
  winStyle.button.colorBRDfocus= colBRDfocus;
  
  winStyle.text.color= col;
  winStyle.text.colorBRD= colBRD;
  winStyle.text.colorHover= colHover;
  winStyle.text.colorFocus= colFocus;
  winStyle.text.colorBRDfocus= colBRDfocus;

  winStyle.edit.color= col;
  winStyle.edit.colorBRD= colBRD;
  winStyle.edit.colorHover= colHover;
  winStyle.edit.colorFocus= colFocus;
  winStyle.edit.colorBRDfocus= colBRDfocus;
  
  //winStyle.loadStyle("winTex1.txt");    << THIS DON'T create no errors
  ix.wsys().selStyle= &winStyle;

  /// dbg window text
  //ix.pr.style= &fntStyle2;
  /*
  ixStaticText *dbgText= ix.wsys().createStaticText(dbgWatches, 10, 10, 250, 250);
  dbgText->text.font= *ix.pr.style;
  dbgText->setFont(ix.pr.style->selFont);
  str32 txt("Right mouse button: select unit\nLeft mouse button: move unit\nMiddle mouse button: move map\nMouse scroll wheel: zoom map");
  dbgText->setText32(&txt);
  */

  ix.pr.style= &fntStyle2;

  int width= 200;

  w1= ix.wsys().createWindow("Input file", null, ix.win->x0,    ix.win->y0, width, ix.win->dy);
  w1->hook.set(ix.win, ixEBorder::topLeft, ixEBorder::topLeft);
  w1->usage.movable= false;
  w1->usage.resizeable= false;
  w1->usage.autoScrollbars(true);
  
  w2= ix.wsys().createWindow("I3D",        null, ix.win->x0+ ix.win->dx- width, ix.win->y0, width, ix.win->dy);
  w2->hook.set(ix.win, ixEBorder::topRight, ixEBorder::topRight);
  w2->usage.movable= false;
  w2->usage.resizeable= false;
  w2->usage.autoScrollbars(true);

  ix.pr.style= &fntStyle1;
  i.butLoad= ix.wsys().createButton("Load file", w1, 2, 20, 60, 15);
  i.butLoad->usage.movable= false;
  i.butLoad->usage.resizeable= false;
  i.butLoad->usage.toggleable= false;
  

  // input numbers
  //nMeshes= ix.wsys().createStaticText(w1, 3, 40, w1->pos.dx- 6, 15);
  //nMeshes->usage.movable= false;
  //nMeshes->usage.hasCursor= false;

  vec3i p(3, 40, 0);
  i.nMeshes=  w1->printStatic("Meshes[0]",    &p); p.y+= 12;
  i.nMats=    w1->printStatic("Materials[0]", &p); p.y+= 12;
  i.nTex=     w1->printStatic("Textures[0]",  &p); p.y+= 12;
  i.nAnims=   w1->printStatic("Anims[0]",     &p); p.y+= 12;
  i.nLights=  w1->printStatic("Lights[0]",    &p); p.y+= 12;
  i.nCameras= w1->printStatic("Cameras[0]",   &p);


  // mesh --------------------
  p.y+= 15;
  i.lMesh= ix.wsys().createDropList(w1, p.x, p.y, w1->pos.dx- 6- 15, 15);
  i.lMesh->usage.setListMaxLength(100);
  //lMesh->addOption("Mesh sel none");

  p.y+= 15;
  i.b1visualize= ix.wsys().createButton("visualize sel", w1, p.x, p.y, 100, 15);
  i.b1visualize->usage.toggleable= false;

  p.y+= 15;
  i.meshVert=      w1->printStatic("", &p); p.y+= 12;
  i.meshNorm=      w1->printStatic("", &p); p.y+= 12;
  i.meshTexCoords= w1->printStatic("", &p); p.y+= 12;
  i.meshMat=       w1->printStatic("", &p);

  //i.meshLastSel= 0;
  //i.matLastSel= 0;


  // material ---------------

  p.y+= 30;
  i.lMats= ix.wsys().createDropList(w1, p.x, p.y, w1->pos.dx- 6- 15, 15);
  i.lMats->usage.setListMaxLength(100);
  //lMats->addOption("Mat sel none");
  p.y+= 20;

  p.y+= 15;         i.matButDiffuse=       ix.wsys().createButton("", w1, p.x, p.y, 14, 14);
  p.x+= 15;         i.matDiffuse= w1->printStatic("", &p);

  p.y+= 15, p.x-= 15; i.matButAmbient=     ix.wsys().createButton("", w1, p.x, p.y, 14, 14);
  p.x+= 15;           i.matAmbient= w1->printStatic("", &p);

  p.y+= 15, p.x-= 15; i.matButSpecular=    ix.wsys().createButton("", w1, p.x, p.y, 14, 14);
  p.x+= 15;           i.matSpecular= w1->printStatic("", &p);
  
  p.y+= 15, p.x-= 15; i.matButEmissive=    ix.wsys().createButton("", w1, p.x, p.y, 14, 14);
  p.x+= 15;           i.matEmissive= w1->printStatic("", &p);

  p.y+= 15, p.x-= 15; i.matButTransparent= ix.wsys().createButton("", w1, p.x, p.y, 14, 14);
  p.x+= 15;           i.matTransparent= w1->printStatic("", &p);

  p.y+= 15, p.x-= 15; i.matButReflective=  ix.wsys().createButton("", w1, p.x, p.y, 14, 14);
  p.x+= 15;           i.matReflective= w1->printStatic("", &p);

  p.x-= 15;



  // output I3D file

  p.y= 40; 
  o.load=   ix.wsys().createButton("Load", w2, p.x, p.y, 50, 15);
  o.update= ix.wsys().createButton("Update", w2, p.x+ 55, p.y, 50, 15);
  p.y+= 20;
  o.save=   ix.wsys().createButton("Save", w2, p.x, p.y, 50, 15);
  o.saveAs= ix.wsys().createButton("SaveAs", w2, p.x+ 55, p.y, 50, 15);
  p.y+= 20;
  o.importFromCurrent= ix.wsys().createButton("IMPORT from left selection", w2, p.x, p.y, width- 6- 15, 15);
  p.y+= 30;
  ix.wsys().createButton("Visualize", w2, p.x, p.y, 50, 15);

  p.y+= 25;
  o.fileName= w2->printStatic("", &p);

  p.y+= 15; o.fileIndex=      w2->printStatic("", &p);
  p.y+= 15; o.inputFileName=  w2->printStatic("", &p);
  p.y+= 15; o.name=           w2->printStatic("", &p);

  p.y+= 15; o.flagsKeepHostData= w2->printStatic("", &p);

  //p.y+= 15; o.dataType= w2->printStatic("", &p);
  //p.y+= 15; o.affinity= w2->printStatic("", &p);

  p.y+= 15; o.dataType= ix.wsys().createDropList(w2, p.x, p.y, width- 6- 15, 15); // w2->printStatic("", &p);
  o.dataType->addOption("Data type 0");
  o.dataType->addOption("Data type 1 interweaved");

  p.y+= 15; o.affinity= ix.wsys().createDropList(w2, p.x, p.y, width- 6- 15, 15); // w2->printStatic("", &p);
  // [def:0] mesh affinity, defining how the mesh will work, internally.
  //  0: own buffer in device memory
  //  1: own buffer in host visible memory
  //  2: shared buffer - it will not handle the buffer in any way, it is given a place in one
  // 64: uber buffer system
  o.affinity->addOption("0: own buf in device mem");
  o.affinity->addOption("1: own buf in host visible mem");
  o.affinity->addOption("2: shared buf- it will not handle the buffer in any way");
  o.affinity->addOption("64: uber buffer sys");

  p.y+= 15; o.nrVert=   w2->printStatic("", &p);
  p.y+= 15; o.dataSize= w2->printStatic("", &p);


  /*
  ixButton *load;
  ixButton *update;
  ixButton *save;
  ixButton *saveAs;
  ixButton *importFromCurrent;
  */


  updateControls();
}



void UI::updateControls() {

  str8 s, name;
  aiString aistr;

  s.f("Meshes[%d]", (input.scene? input.scene->mNumMeshes: 0));       w1->printStaticModify(i.nMeshes, s.d);
  s.f("Materials[%d]", (input.scene? input.scene->mNumMaterials: 0)); w1->printStaticModify(i.nMats, s.d);
  s.f("Textures[%d]", (input.scene? input.scene->mNumTextures: 0));   w1->printStaticModify(i.nTex, s.d);
  s.f("Anims[%d]", (input.scene? input.scene->mNumAnimations: 0));    w1->printStaticModify(i.nAnims, s.d);
  s.f("Lights[%d]", (input.scene? input.scene->mNumLights: 0));       w1->printStaticModify(i.nLights, s.d);
  s.f("Cameras[%d]", (input.scene? input.scene->mNumCameras: 0));     w1->printStaticModify(i.nCameras, s.d);

  //input.scene->mMeshes[0]->mMaterialIndex;

  // must work with these keys it seems.  
  // aiReturn Get(const char *pKey, unsigned int type, unsigned int idx, aiString &pOut) const;
  //input.scene->mMaterials[0]->GetName();    // AI_MATKEY_NAME


  

  // mesh list
  i.lMesh->delAllOptions();
  
  if(input.scene) {
    
    for(uint a= 0; a< input.scene->mNumMeshes; a++) {
      aistr= input.scene->mMeshes[a]->mName;
      name= (aistr.length> 0? aistr.data: "unnamed mesh");

      i.lMesh->addOption(name);
    }
  }


  updateInputMeshDetails();

  // mat list
  i.lMats->delAllOptions();
  if(input.scene) {
    for(uint a= 0; a< input.scene->mNumMaterials; a++) {
      aistr= input.scene->mMaterials[a]->GetName();
      name= (aistr.length> 0? aistr.data: "unnamed mat");

      i.lMats->addOption(name);
    }
  }

  updateInputMatDetails();



  updateOutputMeshDetails();

}


void UI::updateInputMeshDetails() {
  str8 s;
  if(input.scene) {
    s.f("nr Vertices[%d]", input.scene->mMeshes[i.lMesh->selNr]->mNumVertices);                    w1->printStaticModify(i.meshVert, s.d);
    s.f("has normals[%s]", (input.scene->mMeshes[i.lMesh->selNr]->HasNormals()? "true": "false")); w1->printStaticModify(i.meshNorm, s.d);
    s.f("has tex coords0[%s]", (input.scene->mMeshes[i.lMesh->selNr]->HasTextureCoords(0)? "true": "false")); w1->printStaticModify(i.meshTexCoords, s.d);
    s.f("material[%d]", input.scene->mMeshes[i.lMesh->selNr]->mMaterialIndex);                    w1->printStaticModify(i.meshMat,  s.d);
  } else {
    s= "";
    w1->printStaticModify(i.meshVert,      s.d);
    w1->printStaticModify(i.meshNorm,      s.d);
    w1->printStaticModify(i.meshTexCoords, s.d);
    w1->printStaticModify(i.meshMat,       s.d);
  }

  input.meshSel= i.lMesh->selNr;
}


void UI::updateInputMatDetails() {
  str8 s;
  if(input.scene) {

    vec4 c;
    aiColor4D aicol;

    input.scene->mMaterials[i.lMats->selNr]->Get(AI_MATKEY_COLOR_DIFFUSE, aicol);
    i.matButDiffuse->color.set(aicol.r, aicol.g, aicol.b, aicol.a);
    s.f("diffuse[%.2f, %.2f, %.2f, %.2f]", aicol.r, aicol.g, aicol.b, aicol.a);
    w1->printStaticModify(i.matDiffuse, s.d);

    input.scene->mMaterials[i.lMats->selNr]->Get(AI_MATKEY_COLOR_AMBIENT, aicol);
    i.matButAmbient->color.set(aicol.r, aicol.g, aicol.b, aicol.a);
    s.f("ambient[%.2f, %.2f, %.2f, %.2f]", aicol.r, aicol.g, aicol.b, aicol.a);
    w1->printStaticModify(i.matAmbient, s.d);

    input.scene->mMaterials[i.lMats->selNr]->Get(AI_MATKEY_COLOR_SPECULAR, aicol);
    i.matButSpecular->color.set(aicol.r, aicol.g, aicol.b, aicol.a);
    s.f("specular[%.2f, %.2f, %.2f, %.2f]", aicol.r, aicol.g, aicol.b, aicol.a);
    w1->printStaticModify(i.matSpecular, s.d);

    input.scene->mMaterials[i.lMats->selNr]->Get(AI_MATKEY_COLOR_EMISSIVE, aicol);
    i.matButEmissive->color.set(aicol.r, aicol.g, aicol.b, aicol.a);
    s.f("emissive[%.2f, %.2f, %.2f, %.2f]", aicol.r, aicol.g, aicol.b, aicol.a);
    w1->printStaticModify(i.matEmissive, s.d);

    input.scene->mMaterials[i.lMats->selNr]->Get(AI_MATKEY_COLOR_TRANSPARENT, aicol);
    i.matButTransparent->color.set(aicol.r, aicol.g, aicol.b, aicol.a);
    s.f("transparent[%.2f, %.2f, %.2f, %.2f]", aicol.r, aicol.g, aicol.b, aicol.a);
    w1->printStaticModify(i.matTransparent, s.d);

    input.scene->mMaterials[i.lMats->selNr]->Get(AI_MATKEY_COLOR_REFLECTIVE, aicol);
    i.matButReflective->color.set(aicol.r, aicol.g, aicol.b, aicol.a);
    s.f("reflective[%.2f, %.2f, %.2f, %.2f]", aicol.r, aicol.g, aicol.b, aicol.a);
    w1->printStaticModify(i.matReflective, s.d);

    i.matButDiffuse->setVisible(true);
    i.matButAmbient->setVisible(true);
    i.matButSpecular->setVisible(true);
    i.matButEmissive->setVisible(true);
    i.matButTransparent->setVisible(true);
    i.matButReflective->setVisible(true);

  } else {
    s= "";
    w1->printStaticModify(i.matDiffuse, s.d);
    w1->printStaticModify(i.matAmbient, s.d);
    w1->printStaticModify(i.matSpecular, s.d);
    w1->printStaticModify(i.matEmissive, s.d);
    w1->printStaticModify(i.matTransparent, s.d);
    w1->printStaticModify(i.matReflective, s.d);

    i.matButDiffuse->setVisible(false);
    i.matButAmbient->setVisible(false);
    i.matButSpecular->setVisible(false);
    i.matButEmissive->setVisible(false);
    i.matButTransparent->setVisible(false);
    i.matButReflective->setVisible(false);
  }
  input.matSel= i.lMats->selNr;
}


void UI::updateOutputMeshDetails() {
  str8 s;

  s.f("Filename[%s]", output.outMesh.fileName.d);        w2->printStaticModify(o.fileName, s.d);

  s.f("File index[%d]", output.outMesh.fileIndex);       w2->printStaticModify(o.fileIndex, s.d);
  s.f("Input File[%s]", output.outMesh.fileInputName.d); w2->printStaticModify(o.inputFileName, s.d);
  s.f("Mesh name[%s]",  output.outMesh.name);            w2->printStaticModify(o.name, s.d);

  s.f("Flag KeepHostData[%d]", output.outMesh.flags.isUp(0x02));    w2->printStaticModify(o.flagsKeepHostData, s.d);

  /*
  if(output.outMesh.dataType== 0)
    s.f("Data type[%s]", "0");
  else if(output.outMesh.dataType== 1)
    s.f("Data type[%s]", "1 interweaved");
  w2->printStaticModify(o.dataType, s.d);
  */
  //s.f("Affinity[%d]", output.outMesh.affinity);   w2->printStaticModify(o.affinity, s.d);

  o.dataType->select(output.outMesh.dataType);

  if(output.outMesh.affinity== 0)       o.affinity->select(0);
  else if(output.outMesh.affinity== 1)  o.affinity->select(1);
  else if(output.outMesh.affinity== 2)  o.affinity->select(2);
  else if(output.outMesh.affinity== 64) o.affinity->select(3);
  

  s.f("Nr Vertices[%d]", output.outMesh.nrVert);  w2->printStaticModify(o.nrVert, s.d);
  s.f("Data size[%d]", output.outMesh.size);      w2->printStaticModify(o.dataSize, s.d);
}




void UI::updateI3OfromControls() {
  
  if(o.affinity->selNr<= 2) 
    output.outMesh.affinity= o.affinity->selNr;
  else if(o.affinity->selNr== 3)
    output.outMesh.affinity= 64;

  output.outMesh.changeDataType(o.dataType->selNr);
}



















void UI::update() {
  
  if(osi.flags.windowResized) {
    w1->resize(w1->pos.dx, ix.win->dy);
    w2->resize(w2->pos.dx, ix.win->dy);
  }
  


    
  // if wsys had hid interactions, then no update is required anymore
  if(ix.wsys().update()) {
    
    // INPUT window
    /// LOAD
    if(i.butLoad->is.activated) {
      if(input.loadFile()) {
        i.lMesh->select(0);
        i.lMats->select(0);
        updateControls();
      }
      return;
    }

    if(input.meshSel!= i.lMesh->selNr)
      updateInputMeshDetails();
    
    if(input.matSel!= i.lMats->selNr)
      updateInputMatDetails();

    // I3D window
    /// import from input window
    if(o.importFromCurrent->is.activated) {

      uint8 saveAffinity= output.outMesh.affinity;    // mesh will always have own buffer for this program
      ixFlags8 saveFlags= output.outMesh.flags;       

      output.inportMesh_n(&output.outMesh, input.scene, input.meshSel);
      ix.vk.DeviceWaitIdle(ix.vk.device);
      output.mat->updateSet();
      ix.vk.DeviceWaitIdle(ix.vk.device);

      // MATERIAL MUST BE IMPORTED HERE, output.loadMat_n <<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<
      //mat->map[0]= ix.vki.noTexture;
      //output.inportMat_n(..., input.scene, mat number);


      output.outMesh.flags.setUp(0x02);
      output.outMesh.affinity= 0;
      output.outMesh.upload();                        // upload
      output.outMesh.affinity= saveAffinity;
      output.outMesh.flags= saveFlags;
      ix.vk.DeviceWaitIdle(ix.vk.device);

      updateOutputMeshDetails();
    }
    /// save / save button pressed
    if(o.save->is.activated) {
      output.save();
      updateOutputMeshDetails();
    }


    if(ix.wsys().flags.isUp((uint32)ixeWSflags::mouseUsed)) {
      
      return;
    }

    // keyboard chars are not tied to osi.k.lastKey, that should be used, so it won't matter if keyboard was used, i think
    // but other than unicodes can be used... maybe movement of windows with the keyboard? this could be too much, i guess
    // but maybe this can require another flag, unicodesUsed
    if(ix.wsys().flags.isUp((uint32)ixeWSflags::keyboardUsed))
      ;

  }


  // vvvvvvvvvvvvvvvv
  // mouse drag to rotate / move the camera around the object must go here <<<<<<<<<<<<<<<<<<
  // ^^^^^^^^^^^^^^^^

  if(in.m.but[2].down) {
    if(in.m.dx || in.m.dy) {
      /* direction.x= cos(viewer.angle.z)* cos(viewer.angle.x);
         direction.y= sin(viewer.angle.x);
         direction.z= sin(viewer.angle.z)* cos(viewer.angle.x); */
  
      // just using delta angles
      if(in.m.dy)
        ix.cameraPersp.orbitX((float)in.m.dy);
      if(in.m.dx)
        ix.cameraPersp.orbitZ((float)in.m.dx);
      
    }
  }
  if(in.m.wheel) {
    vec3 unit= normalize(ix.cameraPersp.pos);
    if(in.m.wheel> 0)
      ix.cameraPersp.pos+= unit;
    else
      if(ix.cameraPersp.pos.length()> 1.01f)
        ix.cameraPersp.pos-= unit;
    ix.cameraPersp.computeViewMat();
  }
  
}


void UI::draw() {
  ix.startOrtho();
  ix.vk.CmdSetViewport(ix.vki.ortho.cmd[ix.vki.fi]->buffer, 0, 1, &ix.vki.render.viewport);
  ix.vk.CmdSetScissor(ix.vki.ortho.cmd[ix.vki.fi]->buffer, 0, 1, &ix.vki.render.scissor);

  ix.wsys().draw();
  ix.pr.f2((float)(ix.win->x0+ 500), (float)(ix.win->y0+ 0),
           "Camera Position [%2.2fx %2.2fy %2.2fz]", ix.cameraPersp.pos.x, ix.cameraPersp.pos.y, ix.cameraPersp.pos.z);
  ix.console().update();
  

  ix.endOrtho();
}















