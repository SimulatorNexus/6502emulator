@set RAM-size = 8
@set STACK-size = 1

.<start>

    LDA_im, $21;
    LDA_ZP, $02;
    LDA_ZPX, $02;
//    LDA_im, $21;
    LDA_ZP, $05;
//    LDA_im, $42;
//    LDA_ZP, $03;
//    LDA_im, $41;

.<end>
