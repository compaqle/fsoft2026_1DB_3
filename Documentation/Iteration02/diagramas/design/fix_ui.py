import sys

xml_template = """<mxfile host="app.diagrams.net">
  <diagram name="UI-Navigation" id="ui_nav_bw">
    <mxGraphModel dx="1200" dy="1000" grid="1" gridSize="10" guides="1" tooltips="1" connect="1" arrows="1" fold="1" page="1" pageScale="1" pageWidth="1100" pageHeight="850" math="0" shadow="0">
      <root>
        <mxCell id="0" />
        <mxCell id="1" parent="0" />

        <!-- Menu Principal -->
        <mxCell id="menu_principal" parent="1" style="rounded=0;whiteSpace=wrap;html=1;fontStyle=1;fontSize=12;fillColor=#ffffff;strokeColor=#000000;align=left;spacingLeft=8;strokeWidth=2;" value="Menu Principal&#xa;0. Perfil ADMIN&#xa;1...n. Perfil CAIXA (ID)&#xa;-1. Sair da Aplicação" vertex="1">
          <mxGeometry height="80" width="220" x="420" y="20" as="geometry" />
        </mxCell>

        <!-- Menu Admin -->
        <mxCell id="menu_admin" parent="1" style="rounded=0;whiteSpace=wrap;html=1;fontStyle=1;fontSize=11;fillColor=#ffffff;strokeColor=#000000;align=left;spacingLeft=8;strokeWidth=1.5;" value="Menu ADMIN&#xa;1. Gerir Catálogo&#xa;2. Gerir Categorias&#xa;3. Gerir Utilizadores*&#xa;4. Consultar Estatísticas*&#xa;5. Gerir Promoções*&#xa;6. Gerir Clientes*&#xa;0. Voltar ao Início" vertex="1">
          <mxGeometry height="140" width="200" x="150" y="160" as="geometry" />
        </mxCell>

        <!-- Gerir Catalogo -->
        <mxCell id="menu_catalogo" parent="1" style="rounded=0;whiteSpace=wrap;html=1;fontSize=10;fillColor=#ffffff;strokeColor=#000000;align=left;spacingLeft=8;" value="Gerir Catálogo&#xa;1. Criar Produto&#xa;2. Listar Produtos*&#xa;3. Editar Produto*&#xa;4. Remover Produto*&#xa;0. Voltar" vertex="1">
          <mxGeometry height="110" width="180" x="30" y="380" as="geometry" />
        </mxCell>

        <!-- Gerir Categorias -->
        <mxCell id="menu_categorias" parent="1" style="rounded=0;whiteSpace=wrap;html=1;fontSize=10;fillColor=#ffffff;strokeColor=#000000;align=left;spacingLeft=8;" value="Gerir Categorias&#xa;1. Criar Categoria&#xa;2. Listar Categorias*&#xa;3. Remover Categoria*&#xa;0. Voltar" vertex="1">
          <mxGeometry height="100" width="180" x="250" y="380" as="geometry" />
        </mxCell>

        <!-- Menu Caixa -->
        <mxCell id="menu_caixa" parent="1" style="rounded=0;whiteSpace=wrap;html=1;fontStyle=1;fontSize=11;fillColor=#ffffff;strokeColor=#000000;align=left;spacingLeft=8;strokeWidth=1.5;" value="Menu CAIXA (ID: n)&#xa;1. Realizar Venda*&#xa;2. Consultar Preço*&#xa;3. Consultar Pontos*&#xa;0. Voltar ao Início" vertex="1">
          <mxGeometry height="100" width="200" x="650" y="160" as="geometry" />
        </mxCell>

        <!-- Final Terminate -->
        <mxCell id="terminar" parent="1" style="ellipse;whiteSpace=wrap;html=1;fontSize=10;fillColor=#ffffff;strokeColor=#000000;align=center;" value="Terminar" vertex="1">
          <mxGeometry height="40" width="80" x="800" y="40" as="geometry" />
        </mxCell>

        <!-- Notes -->
        <mxCell id="note" parent="1" style="rounded=0;whiteSpace=wrap;html=1;fontSize=9;fillColor=none;strokeColor=none;align=left;fontStyle=2;" value="* Funcionalidade identificada mas ainda em desenvolvimento (Ações de Controller retornam mensagem de status)." vertex="1">
          <mxGeometry height="20" width="450" x="150" y="550" as="geometry" />
        </mxCell>

        <!-- Arrows -->
        <!-- Principal -> Admin [0] -->
        <mxCell id="arr_pa" parent="1" style="endArrow=block;html=1;fontSize=10;endFill=1;exitX=0.25;exitY=1;entryX=0.5;entryY=0;" value="0" edge="1">
          <mxGeometry relative="1" as="geometry">
            <mxPoint x="475" y="100" as="sourcePoint" />
            <mxPoint x="250" y="160" as="targetPoint" />
          </mxGeometry>
        </mxCell>

        <!-- Principal -> Caixa [1...n] -->
        <mxCell id="arr_pc" parent="1" style="endArrow=block;html=1;fontSize=10;endFill=1;exitX=0.75;exitY=1;entryX=0.5;entryY=0;" value="1...n" edge="1">
          <mxGeometry relative="1" as="geometry">
            <mxPoint x="585" y="100" as="sourcePoint" />
            <mxPoint x="750" y="160" as="targetPoint" />
          </mxGeometry>
        </mxCell>
        
        <!-- Principal -> Terminar [-1] -->
        <mxCell id="arr_exit" parent="1" style="endArrow=block;html=1;fontSize=10;endFill=1;exitX=1;exitY=0.5;entryX=0;entryY=0.5;" value="-1" edge="1">
          <mxGeometry relative="1" as="geometry">
            <mxPoint x="640" y="60" as="sourcePoint" />
            <mxPoint x="800" y="60" as="targetPoint" />
          </mxGeometry>
        </mxCell>

        <!-- Admin -> Catalogo [1] -->
        <mxCell id="arr_acat" parent="1" style="endArrow=block;html=1;fontSize=10;endFill=1;exitX=0.25;exitY=1;entryX=0.5;entryY=0;" value="1" edge="1">
          <mxGeometry relative="1" as="geometry">
            <mxPoint x="200" y="300" as="sourcePoint" />
            <mxPoint x="120" y="380" as="targetPoint" />
          </mxGeometry>
        </mxCell>

        <!-- Admin -> Categorias [2] -->
        <mxCell id="arr_acat2" parent="1" style="endArrow=block;html=1;fontSize=10;endFill=1;exitX=0.75;exitY=1;entryX=0.5;entryY=0;" value="2" edge="1">
          <mxGeometry relative="1" as="geometry">
            <mxPoint x="300" y="300" as="sourcePoint" />
            <mxPoint x="340" y="380" as="targetPoint" />
          </mxGeometry>
        </mxCell>

        <!-- Back arrows (dashed) -->
        <mxCell id="back_admin" parent="1" style="endArrow=open;html=1;fontSize=10;dashed=1;endFill=0;exitX=0;exitY=0.25;entryX=0;entryY=0.5;" value="0 (Voltar)" edge="1">
          <mxGeometry relative="1" as="geometry">
            <mxPoint x="150" y="230" as="sourcePoint" />
            <mxPoint x="420" y="60" as="targetPoint" />
            <Array as="points">
              <mxPoint x="100" y="230" />
              <mxPoint x="100" y="60" />
            </Array>
          </mxGeometry>
        </mxCell>

        <mxCell id="back_caixa" parent="1" style="endArrow=open;html=1;fontSize=10;dashed=1;endFill=0;exitX=1;exitY=0.25;entryX=1;entryY=0.5;" value="0 (Voltar)" edge="1">
          <mxGeometry relative="1" as="geometry">
            <mxPoint x="850" y="230" as="sourcePoint" />
            <mxPoint x="640" y="60" as="targetPoint" />
            <Array as="points">
              <mxPoint x="900" y="230" />
              <mxPoint x="900" y="60" />
            </Array>
          </mxGeometry>
        </mxCell>

        <mxCell id="back_sub1" parent="1" style="endArrow=open;html=1;fontSize=9;dashed=1;endFill=0;exitX=0.5;exitY=0;entryX=0;entryY=0.75;" value="0" edge="1">
          <mxGeometry relative="1" as="geometry">
            <mxPoint x="120" y="380" as="sourcePoint" />
            <mxPoint x="150" y="265" as="targetPoint" />
            <Array as="points">
              <mxPoint x="120" y="340" />
              <mxPoint x="130" y="340" />
              <mxPoint x="130" y="265" />
            </Array>
          </mxGeometry>
        </mxCell>

        <mxCell id="back_sub2" parent="1" style="endArrow=open;html=1;fontSize=9;dashed=1;endFill=0;exitX=0.5;exitY=0;entryX=1;entryY=0.75;" value="0" edge="1">
          <mxGeometry relative="1" as="geometry">
            <mxPoint x="340" y="380" as="sourcePoint" />
            <mxPoint x="350" y="265" as="targetPoint" />
            <Array as="points">
              <mxPoint x="340" y="340" />
              <mxPoint x="370" y="340" />
              <mxPoint x="370" y="265" />
            </Array>
          </mxGeometry>
        </mxCell>

      </root>
    </mxGraphModel>
  </diagram>
</mxfile>
"""
with open("ui_navigation.drawio", "w") as f:
    f.write(xml_template)
