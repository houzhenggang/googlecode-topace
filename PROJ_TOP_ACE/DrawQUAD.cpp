#include "DrawQUAD.h"
GLfloat QUADArrayTexCoord[]={
	1.0f,1.0f,
	0.0f,1.0f,
	1.0f,0.0f,
	0.0f,0.0f};
GLfloat QUADArrayTexCoord2[]={
	1.0f,1.0f,
	0.0f,1.0f,
	1.0f,0.0f,
	0.0f,0.0f};
GLint QUADArrayVertex[]={
	1,1,
	0,1,
	1,0,
	0,0};
GLfloat QUADArrayVertexF[]={
	1.0,1.0,
	0.0,1.0,
	1.0,0.0,
	0.0,0.0};
void DrawQUAD(GLuint Left,GLuint Right,GLuint Up,GLuint Down)
{
	QUADArrayVertex[2]=QUADArrayVertex[6]=Left;
	QUADArrayVertex[0]=QUADArrayVertex[4]=Right;
	QUADArrayVertex[1]=QUADArrayVertex[3]=Up;
	QUADArrayVertex[5]=QUADArrayVertex[7]=Down;
	
	glEnableClientState( GL_VERTEX_ARRAY );
	glEnableClientState( GL_TEXTURE_COORD_ARRAY );
	glTexCoordPointer( 2, GL_FLOAT, 0, QUADArrayTexCoord );
	glVertexPointer( 2, GL_INT, 0, QUADArrayVertex );
	glDrawArrays(GL_TRIANGLE_STRIP,0,4);
	glDisableClientState( GL_VERTEX_ARRAY );
	glDisableClientState( GL_TEXTURE_COORD_ARRAY );
}
/*
void DrawQUAD_Att(GLuint Left,GLuint Right,GLuint Up,GLuint Down,GLint AttIndexTexCoord,GLint AttIndexVertex)
{
	QUADArrayVertex[2]=QUADArrayVertex[6]=Left;
	QUADArrayVertex[0]=QUADArrayVertex[4]=Right;
	QUADArrayVertex[1]=QUADArrayVertex[3]=Up;
	QUADArrayVertex[5]=QUADArrayVertex[7]=Down;

	glEnableClientState( GL_VERTEX_ARRAY );
	glVertexAttribPointer(AttIndexTexCoord,2,GL_FLOAT,0,0,QUADArrayTexCoord);
	glVertexAttribPointer(AttIndexVertex,2,GL_INT,0,0,QUADArrayVertex);
	glDrawArrays(GL_TRIANGLE_STRIP,0,4);
	glDisableClientState( GL_VERTEX_ARRAY );
}*/
void DrawQUAD(GLfloat Left,GLfloat Right,GLfloat Up,GLfloat Down,GLfloat QUADW,GLfloat QUADH)
{
	
	QUADArrayTexCoord2[0]=QUADArrayTexCoord2[4]=QUADW;
	//QUADArrayTexCoord2[1]=QUADArrayTexCoord2[3]=QUADH;
	QUADArrayTexCoord2[1]=QUADArrayTexCoord2[3]=1.0f-QUADH;
	QUADArrayTexCoord2[5]=QUADArrayTexCoord2[7]=1.0f;
	QUADArrayVertexF[2]=QUADArrayVertexF[6]=Left;
	QUADArrayVertexF[0]=QUADArrayVertexF[4]=Right;
	QUADArrayVertexF[1]=QUADArrayVertexF[3]=Up;
	QUADArrayVertexF[5]=QUADArrayVertexF[7]=Down;
	glEnableClientState( GL_VERTEX_ARRAY );
	glEnableClientState( GL_TEXTURE_COORD_ARRAY );
	glTexCoordPointer( 2, GL_FLOAT, 0, QUADArrayTexCoord2 );
	glVertexPointer( 2, GL_FLOAT, 0, QUADArrayVertexF );
	glDrawArrays(GL_TRIANGLE_STRIP,0,4);
	glDisableClientState( GL_VERTEX_ARRAY );
	glDisableClientState( GL_TEXTURE_COORD_ARRAY );
}
void DrawQUAD_RECT(GLfloat Left,GLfloat Right,GLfloat Up,GLfloat Down,GLfloat QUADW,GLfloat QUADH)
{
	
	QUADArrayTexCoord2[0]=QUADArrayTexCoord2[4]=QUADW;
	//QUADArrayTexCoord2[1]=QUADArrayTexCoord2[3]=QUADH;
	QUADArrayTexCoord2[1]=QUADArrayTexCoord2[3]=QUADH;
	QUADArrayTexCoord2[5]=QUADArrayTexCoord2[7]=0.0f;
	QUADArrayVertexF[2]=QUADArrayVertexF[6]=Left;
	QUADArrayVertexF[0]=QUADArrayVertexF[4]=Right;
	QUADArrayVertexF[1]=QUADArrayVertexF[3]=Up;
	QUADArrayVertexF[5]=QUADArrayVertexF[7]=Down;
	glEnableClientState( GL_VERTEX_ARRAY );
	glEnableClientState( GL_TEXTURE_COORD_ARRAY );
	glTexCoordPointer( 2, GL_FLOAT, 0, QUADArrayTexCoord2 );
	glVertexPointer( 2, GL_FLOAT, 0, QUADArrayVertexF );
	glDrawArrays(GL_TRIANGLE_STRIP,0,4);
	glDisableClientState( GL_VERTEX_ARRAY );
	glDisableClientState( GL_TEXTURE_COORD_ARRAY );
}
void DrawQUAD_Att(GLuint Left,GLuint Right,GLuint Up,GLuint Down,GLint AttIndexTexCoord,GLint AttIndexVertex,int winW,int winH)
{
	QUADArrayTexCoord2[0]=QUADArrayTexCoord2[4]=float(winW);
	QUADArrayTexCoord2[1]=QUADArrayTexCoord2[3]=float(winH);
	QUADArrayTexCoord2[5]=QUADArrayTexCoord2[7]=0.0f;
	QUADArrayVertex[2]=QUADArrayVertex[6]=Left;
	QUADArrayVertex[0]=QUADArrayVertex[4]=Right;
	QUADArrayVertex[1]=QUADArrayVertex[3]=Up;
	QUADArrayVertex[5]=QUADArrayVertex[7]=Down;
	

	glEnableClientState( GL_VERTEX_ARRAY );
	glVertexAttribPointer(AttIndexTexCoord,2,GL_FLOAT,0,0,QUADArrayTexCoord2);
	glVertexAttribPointer(AttIndexVertex,2,GL_INT,0,0,QUADArrayVertex);
	glDrawArrays(GL_TRIANGLE_STRIP,0,4);
	glDisableClientState( GL_VERTEX_ARRAY );
}
void DrawQUAD_Att_RECT(GLuint Left,GLuint Right,GLuint Up,GLuint Down,GLint AttIndexTexCoord,GLint AttIndexVertex,int winW,int winH)
{
	QUADArrayTexCoord2[0]=QUADArrayTexCoord2[4]=float(winW);
	QUADArrayTexCoord2[1]=QUADArrayTexCoord2[3]=float(winH);
	QUADArrayTexCoord2[5]=QUADArrayTexCoord2[7]=0.0f;
	QUADArrayVertex[2]=QUADArrayVertex[6]=Left;
	QUADArrayVertex[0]=QUADArrayVertex[4]=Right;
	QUADArrayVertex[1]=QUADArrayVertex[3]=Up;
	QUADArrayVertex[5]=QUADArrayVertex[7]=Down;
	

	glEnableClientState( GL_VERTEX_ARRAY );
	glVertexAttribPointer(AttIndexTexCoord,2,GL_FLOAT,0,0,QUADArrayTexCoord2);
	glVertexAttribPointer(AttIndexVertex,2,GL_INT,0,0,QUADArrayVertex);
	glDrawArrays(GL_TRIANGLE_STRIP,0,4);
	glDisableClientState( GL_VERTEX_ARRAY );
}
void DrawQUADF(GLfloat Left,GLfloat Right,GLfloat Up,GLfloat Down)
{
	QUADArrayVertexF[2]=QUADArrayVertexF[6]=Left;
	QUADArrayVertexF[0]=QUADArrayVertexF[4]=Right;
	QUADArrayVertexF[1]=QUADArrayVertexF[3]=Up;
	QUADArrayVertexF[5]=QUADArrayVertexF[7]=Down;
	glEnableClientState( GL_VERTEX_ARRAY );
	glEnableClientState( GL_TEXTURE_COORD_ARRAY );
	glTexCoordPointer( 2, GL_FLOAT, 0, QUADArrayTexCoord );
	glVertexPointer( 2, GL_FLOAT, 0, QUADArrayVertexF );
	glDrawArrays(GL_TRIANGLE_STRIP,0,4);
	glDisableClientState( GL_VERTEX_ARRAY );
	glDisableClientState( GL_TEXTURE_COORD_ARRAY );
}
void DrawQUADEX(GLuint TexID,GLuint Left,GLuint Right,GLuint Up,GLuint Down,GLuint winW,GLuint winH)
{
	glDisable( GL_CULL_FACE );
	glEnable(GL_TEXTURE_2D);
	glBindTexture(GL_TEXTURE_2D, TexID);			// Select Our Font Texture
	glDisable(GL_DEPTH_TEST);							// Disables Depth Testing
	glMatrixMode(GL_PROJECTION);						// Select The Projection Matrix
	glPushMatrix();										// Store The Projection Matrix
	glLoadIdentity();									// Reset The Projection Matrix
	glOrtho(0,winW,0,winH,-1,1);							// Set Up An Ortho Screen
	glMatrixMode(GL_MODELVIEW);							// Select The Modelview Matrix
	glPushMatrix();										// Store The Modelview Matrix
	glLoadIdentity();									// Reset The Modelview Matrix
	DrawQUAD(Left,Right,Up,Down);

	glMatrixMode(GL_PROJECTION);						// Select The Projection Matrix
	glPopMatrix();										// Restore The Old Projection Matrix
	glMatrixMode(GL_MODELVIEW);							// Select The Modelview Matrix
	glPopMatrix();										// Restore The Old Projection Matrix
	glEnable(GL_DEPTH_TEST);							// Enables Depth Testing
	glEnable( GL_CULL_FACE );
}
void DrawQUADEX_RECT(GLuint TexID,GLuint Left,GLuint Right,GLuint Up,GLuint Down,GLuint winW,GLuint winH)
{
	glDisable( GL_CULL_FACE );
	
	glDisable(GL_TEXTURE_2D);
	glEnable(GL_TEXTURE_RECTANGLE);
	glBindTexture(GL_TEXTURE_RECTANGLE, TexID);			// Select Our Font Texture
	glDisable(GL_DEPTH_TEST);							// Disables Depth Testing
	glMatrixMode(GL_PROJECTION);						// Select The Projection Matrix
	glPushMatrix();										// Store The Projection Matrix
	glLoadIdentity();									// Reset The Projection Matrix
	glOrtho(0,winW,0,winH,-1,1);							// Set Up An Ortho Screen
	glMatrixMode(GL_MODELVIEW);							// Select The Modelview Matrix
	glPushMatrix();										// Store The Modelview Matrix
	glLoadIdentity();									// Reset The Modelview Matrix
	DrawQUAD_RECT(Left,Right,Up,Down,winW,winH);

	glMatrixMode(GL_PROJECTION);						// Select The Projection Matrix
	glPopMatrix();										// Restore The Old Projection Matrix
	glMatrixMode(GL_MODELVIEW);							// Select The Modelview Matrix
	glPopMatrix();										// Restore The Old Projection Matrix
	glEnable(GL_DEPTH_TEST);							// Enables Depth Testing
	glEnable( GL_CULL_FACE );
}
void DrawQUADEX_NOTEX(GLuint Left,GLuint Right,GLuint Up,GLuint Down,GLuint winW,GLuint winH)
{
	glDisable( GL_CULL_FACE );
	glDisable(GL_TEXTURE_2D);
	glDisable(GL_DEPTH_TEST);							// Disables Depth Testing
	glMatrixMode(GL_PROJECTION);						// Select The Projection Matrix
	glPushMatrix();										// Store The Projection Matrix
	glLoadIdentity();									// Reset The Projection Matrix
	glOrtho(0,winW,0,winH,-1,1);							// Set Up An Ortho Screen
	glMatrixMode(GL_MODELVIEW);							// Select The Modelview Matrix
	glPushMatrix();										// Store The Modelview Matrix
	glLoadIdentity();									// Reset The Modelview Matrix
	DrawQUAD(Left,Right,Up,Down);

	glMatrixMode(GL_PROJECTION);						// Select The Projection Matrix
	glPopMatrix();										// Restore The Old Projection Matrix
	glMatrixMode(GL_MODELVIEW);							// Select The Modelview Matrix
	glPopMatrix();										// Restore The Old Projection Matrix
	glEnable(GL_DEPTH_TEST);							// Enables Depth Testing
	glEnable( GL_CULL_FACE );
}