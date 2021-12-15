# Messenger
Make messenger, instead Server use SQL DataBase. Make two dialog windows, in one of them will be user, in the other one will display a message from the user.
Use Qt.
Use multithread to provide message flow without delay.
Messages might be removed but only from dialog window not DataBase. It's like function "Clear".

![Screenshot from 2021-12-04 02-53-23](https://user-images.githubusercontent.com/34602478/144687290-2d985f04-785b-4803-92a5-38abbab36c22.png)


<mxfile host="app.diagrams.net" modified="2021-12-15T11:16:02.396Z" agent="5.0 (X11)" etag="cChPi7wDn4cXQhVk8uai" version="15.9.6" type="github">
  <diagram id="YlhNQHUDZTMehJpkbUOb" name="Page-1">
    <mxGraphModel dx="2062" dy="1180" grid="1" gridSize="10" guides="1" tooltips="1" connect="1" arrows="1" fold="1" page="1" pageScale="1" pageWidth="850" pageHeight="1100" math="0" shadow="0">
      <root>
        <mxCell id="0" />
        <mxCell id="1" parent="0" />
        <mxCell id="NiT1GDuZARQHEXf_eHMA-1" value="" style="rounded=0;whiteSpace=wrap;html=1;" vertex="1" parent="1">
          <mxGeometry y="160" width="850" height="280" as="geometry" />
        </mxCell>
        <mxCell id="NiT1GDuZARQHEXf_eHMA-2" value="" style="endArrow=none;html=1;rounded=0;entryX=0.25;entryY=1;entryDx=0;entryDy=0;exitX=0.25;exitY=0;exitDx=0;exitDy=0;" edge="1" parent="1" source="NiT1GDuZARQHEXf_eHMA-1" target="NiT1GDuZARQHEXf_eHMA-1">
          <mxGeometry width="50" height="50" relative="1" as="geometry">
            <mxPoint x="400" y="630" as="sourcePoint" />
            <mxPoint x="450" y="580" as="targetPoint" />
            <Array as="points" />
          </mxGeometry>
        </mxCell>
        <mxCell id="NiT1GDuZARQHEXf_eHMA-3" value="" style="endArrow=none;html=1;rounded=0;entryX=0.5;entryY=0;entryDx=0;entryDy=0;exitX=0.5;exitY=1;exitDx=0;exitDy=0;" edge="1" parent="1" source="NiT1GDuZARQHEXf_eHMA-1" target="NiT1GDuZARQHEXf_eHMA-1">
          <mxGeometry width="50" height="50" relative="1" as="geometry">
            <mxPoint x="400" y="630" as="sourcePoint" />
            <mxPoint x="450" y="580" as="targetPoint" />
          </mxGeometry>
        </mxCell>
        <mxCell id="NiT1GDuZARQHEXf_eHMA-5" value="" style="endArrow=none;html=1;rounded=0;entryX=0.75;entryY=0;entryDx=0;entryDy=0;exitX=0.75;exitY=1;exitDx=0;exitDy=0;" edge="1" parent="1" source="NiT1GDuZARQHEXf_eHMA-1" target="NiT1GDuZARQHEXf_eHMA-1">
          <mxGeometry width="50" height="50" relative="1" as="geometry">
            <mxPoint x="400" y="630" as="sourcePoint" />
            <mxPoint x="450" y="580" as="targetPoint" />
          </mxGeometry>
        </mxCell>
        <mxCell id="NiT1GDuZARQHEXf_eHMA-6" value="" style="endArrow=none;html=1;rounded=0;entryX=0;entryY=0.25;entryDx=0;entryDy=0;exitX=1;exitY=0.25;exitDx=0;exitDy=0;" edge="1" parent="1" source="NiT1GDuZARQHEXf_eHMA-1" target="NiT1GDuZARQHEXf_eHMA-1">
          <mxGeometry width="50" height="50" relative="1" as="geometry">
            <mxPoint x="400" y="630" as="sourcePoint" />
            <mxPoint x="450" y="580" as="targetPoint" />
          </mxGeometry>
        </mxCell>
        <mxCell id="NiT1GDuZARQHEXf_eHMA-8" value="Id" style="text;strokeColor=none;fillColor=none;align=left;verticalAlign=middle;spacingLeft=4;spacingRight=4;overflow=hidden;points=[[0,0.5],[1,0.5]];portConstraint=eastwest;rotatable=0;fontSize=20;" vertex="1" parent="1">
          <mxGeometry y="180" width="210" height="30" as="geometry" />
        </mxCell>
        <mxCell id="NiT1GDuZARQHEXf_eHMA-9" value="user_name" style="text;strokeColor=none;fillColor=none;align=left;verticalAlign=middle;spacingLeft=4;spacingRight=4;overflow=hidden;points=[[0,0.5],[1,0.5]];portConstraint=eastwest;rotatable=0;fontSize=20;" vertex="1" parent="1">
          <mxGeometry x="215" y="180" width="205" height="30" as="geometry" />
        </mxCell>
        <mxCell id="NiT1GDuZARQHEXf_eHMA-10" value="data" style="text;strokeColor=none;fillColor=none;align=left;verticalAlign=middle;spacingLeft=4;spacingRight=4;overflow=hidden;points=[[0,0.5],[1,0.5]];portConstraint=eastwest;rotatable=0;fontSize=20;" vertex="1" parent="1">
          <mxGeometry x="425" y="180" width="205" height="30" as="geometry" />
        </mxCell>
        <mxCell id="NiT1GDuZARQHEXf_eHMA-11" value="hash" style="text;strokeColor=none;fillColor=none;align=left;verticalAlign=middle;spacingLeft=4;spacingRight=4;overflow=hidden;points=[[0,0.5],[1,0.5]];portConstraint=eastwest;rotatable=0;fontSize=20;" vertex="1" parent="1">
          <mxGeometry x="640" y="180" width="205" height="30" as="geometry" />
        </mxCell>
      </root>
    </mxGraphModel>
  </diagram>
</mxfile>
